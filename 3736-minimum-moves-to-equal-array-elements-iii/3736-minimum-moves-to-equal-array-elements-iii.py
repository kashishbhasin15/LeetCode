class Solution(object):
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxn=max(nums)
        count=0

        for i in range(len(nums)):
            if nums[i]<maxn:
                ct=maxn-nums[i]
                count+=ct
        return count