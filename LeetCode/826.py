class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        profile = [(0,0)]
        for i in range(len(difficulty)):
            profile.append((difficulty[i],profit[i]))

        profile.sort()
        for i in range(len(profile) - 1):
            profile[i + 1] = (
                profile[i + 1][0], max(profile[i][1], profile[i + 1][1])
            )


        net = 0
        for i in range(len(worker)):
            left, right = 0, len(profile) - 1
            jobProfit = 0

            while left <= right:
                mid = (left + right) // 2
                if profile[mid][0] <= worker[i]:
                    jobProfit = max(jobProfit, profile[mid][1])
                    left = mid + 1

                else:
                    right = mid - 1

            net += jobProfit
        
        return net        
