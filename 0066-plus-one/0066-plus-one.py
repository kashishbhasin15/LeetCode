class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        
        n=len(digits)
        num=digits[n-1]+1

        if num!=10:
            digits[n-1]=num
        else:
            for i in range(n-1,-1,-1):
                if digits[i]<9:
                    digits[i]=digits[i]+1
                    return digits
                digits[i]=0
            digits.insert(0,1)
        return digits
        