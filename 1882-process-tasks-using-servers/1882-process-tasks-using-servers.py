# class Solution(object):
#     def assignTasks(self, servers, tasks):
#         """
#         :type servers: List[int]
#         :type tasks: List[int]
#         :rtype: List[int]
#         """


import heapq

class Solution(object):
    def assignTasks(self, servers, tasks):
        available = [(w, i) for i, w in enumerate(servers)]
        heapq.heapify(available)

        busy = []
        ans = []

        time = 0

        for i, duration in enumerate(tasks):

            time = max(time, i)

            # Release servers that have completed their tasks
            while busy and busy[0][0] <= time:
                end, weight, index = heapq.heappop(busy)
                heapq.heappush(available, (weight, index))

            # If all servers are busy, wait
            if not available:
                time = busy[0][0]

                while busy and busy[0][0] <= time:
                    end, weight, index = heapq.heappop(busy)
                    heapq.heappush(available, (weight, index))

            # Select the server with lowest weight, then index
            weight, index = heapq.heappop(available)

            ans.append(index)

            # Store finishing time
            heapq.heappush(
                busy,
                (time + duration, weight, index)
            )

        return ans