class Solution:
    def minKBitFlips(self, nums: List[int], k: int) -> int:
        n = len(nums)
        flipped = [False] * n
        goodFlips = 0
        count = 0

        for i in range(n):
            if i >= k:
                if flipped[i -k]:
                    goodFlips -= 1

            if goodFlips % 2 == nums[i]:
                if i + k > n: return -1

                goodFlips += 1
                flipped[i] = True
                count += 1
                
        return count
        
