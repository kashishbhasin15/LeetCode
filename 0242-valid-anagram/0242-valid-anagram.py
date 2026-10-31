class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        count1=len(s)
        count2=len(t)
        count3=0
        
        if count1!=count2:
            return False
        
        s=sorted(s)
        t=sorted(t)

        for i in range(count1):
            if s[i]!=t[i]:
                break
            else:
                count3+=1

        if(count3==count1):
            return True
        else:
            return False      
        