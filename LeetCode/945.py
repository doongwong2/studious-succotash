class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums = sorted(nums)
        steps = 0
        currentLargest = 0

        for i in range(len(nums)):
            currentLargest = max(currentLargest,nums[i])
            steps += currentLargest - nums[i]
            currentLargest += 1

        return steps
        
