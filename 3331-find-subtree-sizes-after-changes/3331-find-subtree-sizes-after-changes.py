class Solution(object):
    def findSubtreeSizes(self, parent, s):
        n = len(parent)

        g = [[] for _ in range(n)]
        for i in range(1, n):
            g[parent[i]].append(i)

        ans = [0] * n
        path = [[] for _ in range(26)]

        def dfs(u, par):
            ans[u] = 1

            c = ord(s[u]) - ord('a')
            path[c].append(u)

            for v in g[u]:
                dfs(v, u)

            target = par

            if len(path[c]) >= 2:
                target = path[c][-2]

            if target != -1:
                ans[target] += ans[u]

            path[c].pop()

        dfs(0, -1)
        return ans