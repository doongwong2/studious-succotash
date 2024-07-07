class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = 0
        while numBottles >= numExchange:
            ans += numExchange
            numBottles -= numExchange
            numBottles += 1
    
        return ans + numBottles
