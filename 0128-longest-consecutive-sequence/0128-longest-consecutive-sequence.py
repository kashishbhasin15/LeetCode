class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        nums=sorted(nums)
        count=1
        best=1
        if len(nums)==0:
            return 0
        for i in range(1,len(nums)):
                if (nums[i]-nums[i-1]==1):
                    count+=1
                elif nums[i]==nums[i-1]:
                    continue
                else:
                    best=max(best,count)
                    count=1
        return max(best,count)