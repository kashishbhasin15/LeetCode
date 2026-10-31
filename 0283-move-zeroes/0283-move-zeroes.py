class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        point=0
        for i in range(0,len(nums)):
            if(nums[i]!=0):
                temp=nums[i]
                nums[i]=nums[point]
                nums[point]=temp
                point+=1
        return nums
        