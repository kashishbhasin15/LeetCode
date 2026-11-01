class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        
        # count=0
        # prev=0
        # best=float('inf')
        # btcount=0

        # for i in range(0,len(nums)):
        #     total=0
        #     count=0
        #     for j in range(i,len(nums)):
        #         total+=nums[j]
        #         count+=1
        #         if(total>=target):
        #             best=min(best,count)
        #             break

        # return 0 if best==float('inf') else best

        left=0
        total=0
        best=float('inf')

        for right in range(len(nums)):
            total+=nums[right]
            while total>=target:
                best=min(best,right-left+1)
                total-=nums[left]
                left+=1
        return 0 if best==float('inf') else best