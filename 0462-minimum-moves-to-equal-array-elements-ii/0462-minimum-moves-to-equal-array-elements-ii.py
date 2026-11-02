class Solution(object):
    def minMoves2(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        nums.sort()
        moves=0

        left=0
        right=len(nums)-1
        median=(left+right)//2

        for i in range(len(nums)):
            moves+=abs(nums[i]-nums[median])
        
        return moves

        