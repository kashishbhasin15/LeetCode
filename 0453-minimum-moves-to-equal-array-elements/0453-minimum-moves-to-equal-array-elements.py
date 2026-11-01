class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        minimum=min(nums)
        sums=sum(nums)

        return sums-(len(nums)*minimum)