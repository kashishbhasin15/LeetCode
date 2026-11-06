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


class Solution(object):
    def countServers(self, n, logs, x, queries):
        logs.sort(key=lambda a: a[1])

        sorted_queries = sorted(
            (q, i) for i, q in enumerate(queries)
        )

        ans = [0] * len(queries)
        count = [0] * (n + 1)

        left = 0
        right = 0
        active = 0

        for q, idx in sorted_queries:
            start = q - x

            # Add logs whose time is <= query time
            while right < len(logs) and logs[right][1] <= q:
                server = logs[right][0]

                if count[server] == 0:
                    active += 1

                count[server] += 1
                right += 1

            # Remove logs whose time is < start
            while left < right and logs[left][1] < start:
                server = logs[left][0]

                count[server] -= 1

                if count[server] == 0:
                    active -= 1

                left += 1

            ans[idx] = n - active

        return ans