class Solution(object):
    def findTheDistanceValue(self, arr1, arr2, d):
        """
        :type arr1: List[int]
        :type arr2: List[int]
        :type d: int
        :rtype: int
        """
        count=0
        k=0
        for i in range(len(arr1)):
            num=arr1[i]
            for j in range(len(arr2)):
                if abs(num-arr2[j])>d:
                    count+=1
            if count==len(arr2):
                k+=1
            count=0
        
        return k