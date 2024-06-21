class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        happy = 0
        unhappy = 0
        cured = 0

        for i in range(len(customers)):
            if grumpy[i] == 0:
                happy += customers[i]
            if grumpy[i] == 1:
                unhappy += customers[i]

        for i in range(len(customers) - minutes + 1):
            temp = 0
            for j in range(minutes):
                if grumpy[i + j] == 1:
                    temp += customers[i + j]

            cured = max(cured, temp)

        return happy + cured
        
        
