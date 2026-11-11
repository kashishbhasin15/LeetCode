class Solution(object):
    def minimumCost(self, cost1, cost2, costBoth, need1, need2):
        """
        :type cost1: int
        :type cost2: int
        :type costBoth: int
        :type need1: int
        :type need2: int
        :rtype: int
        """

        common=min(need1,need2)
        extra1=need1-common
        extra2=need2-common

        result=common*min(costBoth,cost1+cost2)
        result+=extra1*min(costBoth,cost1)
        result+=extra2*min(costBoth,cost2)

        return result
