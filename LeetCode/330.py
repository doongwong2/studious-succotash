class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        missing = 1
        patch = 0
        i = 0
        while missing <= n:
            if i < len(nums) and missing >= nums[i]:
                missing += nums[i]
                i += 1
            else:
                patch += 1
                missing *= 2

        return patch        
