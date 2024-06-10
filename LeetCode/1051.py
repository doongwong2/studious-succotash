class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        check = sorted(heights)
        ans = 0

        for i, j in zip(heights, check):
            if i !=j: ans +=1

        return ans
        
