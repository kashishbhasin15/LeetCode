# class Solution(object):
#     def busiestServers(self, k, arrival, load):
#         """
#         :type k: int
#         :type arrival: List[int]
#         :type load: List[int]
#         :rtype: List[int]
#         """


import heapq
from sortedcontainers import SortedList

class Solution(object):
    def busiestServers(self, k, arrival, load):
        available = SortedList(range(k))
        busy = []
        count = [0] * k

        for i in range(len(arrival)):

            while busy and busy[0][0] <= arrival[i]:
                end, server = heapq.heappop(busy)
                available.add(server)

            if not available:
                continue

            pos = available.bisect_left(i % k)

            if pos == len(available):
                pos = 0

            server = available.pop(pos)

            count[server] += 1

            heapq.heappush(
                busy, (arrival[i] + load[i], server)
            )

        maximum = max(count)

        return [i for i in range(k) if count[i] == maximum]