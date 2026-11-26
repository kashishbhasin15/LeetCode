class Solution:
    def smallestUniqueSubarray(self, nums):
        n = len(nums)

        base = 200003
        mod = (1 << 61) - 1

        power = [1] * (n + 1)
        prefix = [0] * (n + 1)

        for i in range(n):
            power[i + 1] = (power[i] * base) % mod
            prefix[i + 1] = (prefix[i] * base + nums[i]) % mod

        def get_hash(l, r):
            return (prefix[r] - prefix[l] * power[r - l]) % mod

        def check(length):
            freq = {}

            for i in range(n - length + 1):
                h = get_hash(i, i + length)
                freq[h] = freq.get(h, 0) + 1

            return any(cnt == 1 for cnt in freq.values())

        left, right = 1, n
        ans = n

        while left <= right:
            mid = (left + right) // 2

            if check(mid):
                ans = mid
                right = mid - 1
            else:
                left = mid + 1

        return ans