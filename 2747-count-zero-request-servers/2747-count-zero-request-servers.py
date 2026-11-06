# class Solution(object):
#     def countServers(self, n, logs, x, queries):
#         """
#         :type n: int
#         :type logs: List[List[int]]
#         :type x: int
#         :type queries: List[int]
#         :rtype: List[int]
#         """
#         ans=[]
#         for i in range(len(queries)):
#             start=queries[i]-x
#             end=queries[i]
#             active=set()
#             for server,time in logs:
#                 if start<=time<=end:
#                     active.add(server)
#             inactive=n-len(active)
#             ans.append(inactive)
        
#         return ans


from bisect import bisect_left

class Solution(object):
    def countServers(self, n, logs, x, queries):
        server_times = [[] for _ in range(n + 1)]

        for server, time in logs:
            server_times[server].append(time)

        for times in server_times:
            times.sort()

        ans = []

        for q in queries:
            start = q - x
            inactive = 0

            for server in range(1, n + 1):
                times = server_times[server]

                pos = bisect_left(times, start)

                if pos == len(times) or times[pos] > q:
                    inactive += 1

            ans.append(inactive)

        return ans