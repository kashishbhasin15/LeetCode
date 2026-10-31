class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        longest=0
        left=0
        seen=set()

        for right in range(0,len(s)):
            while s[right] in seen:
                seen.remove(s[left])
                left+=1
            seen.add(s[right])
            longest=max(longest,right-left+1)
        return longest   