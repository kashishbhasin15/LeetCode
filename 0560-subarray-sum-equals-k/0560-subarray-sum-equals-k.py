class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        
        # count=0

        # for i in range(len(nums)):
        #     total=0
        #     for j in range(i,len(nums)):
        #         total+=nums[j]
        #         if total==k:
        #            count+=1
        # return count

        count=0
        total=0
        mp={0:1}
        for num in nums:
            total+=num
            diff=total-k
            if diff in mp:
                count+=mp[diff]
            mp[total]=mp.get(total,0)+1
        return count
