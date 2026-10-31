class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # result=[]
        # for i in range(0,len(nums)):
        #     product=1
        #     for j in range(0,len(nums)):
        #         if i!=j:
        #           product=nums[j]*product
        #     result.append(product)
        # return result


        zero_count=nums.count(0)
        product=1

        for x in nums:
            if x!=0:
                product*=x
        result=[]
        for x in nums:
            if zero_count>1:
                result.append(0)
            elif zero_count==1:
                result.append(product if x==0 else 0)
            else :
                result.append(product//x)

        return result        
