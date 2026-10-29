class Solution(object):
    def maxAscendingSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        curr=nums[0]
        best=nums[0]

        # for x in nums[1:]:
        #     curr=max(x,curr+x)
        #     best=max(best,curr)
        # return best

        for i in range(1,len(nums)):
            if nums[i]>nums[i-1]:
                curr+=nums[i]
            else:
                curr=nums[i]
            best=max(best,curr)
        
        return best