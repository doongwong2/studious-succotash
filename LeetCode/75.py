class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        r, w , b = 0,0, len(nums) -1

        while w <= b:
            if nums[w] == 0:
                nums[w], nums[r] = nums[r], nums[w]
                w += 1
                r += 1
            
            elif nums[w] == 1:
                w+= 1

            else :
                nums[w] , nums[b] = nums[b], nums[w]
                b -= 1
            
        
