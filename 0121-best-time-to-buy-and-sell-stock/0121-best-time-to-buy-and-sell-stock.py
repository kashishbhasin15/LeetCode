class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """

        buy=prices[0]
        sell=prices[0]
        profit=0

        for i in range(1,len(prices)):
            if prices[i]<buy:
                buy=prices[i]
            else:
                sell=prices[i]
                profit=max(profit,sell-buy)
        return profit
       

        