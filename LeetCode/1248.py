class Solution:
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        preSum = [0] * (len(nums) + 1)
        preSum[0] =1
        ans = 0
        t = 0
        
        for i in nums:
            t += i & 1
            if t - k >= 0:
                ans += preSum[t - k]
            preSum[t] += 1
        return ans
        
