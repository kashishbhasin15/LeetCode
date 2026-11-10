class Solution(object):
    def climbStairs(self, n, costs):
        """
        :type n: int
        :type costs: List[int]
        :rtype: int
        """
        
        mincost=[float('inf')]*(n+1)
        mincost[0]=0
        cost=0
        for i in range(1,n+1):
            for j in range(1,4):
                if i-j>=0:
                    total=costs[i-1]+j*j
                    mincost[i]=min(mincost[i],mincost[i-j]+total)
        return mincost[n]