class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        div = 2
        while div ** 2 <= c:
            if c % div == 0:
                count = 0
                while c % div == 0:
                    count += 1
                    c //= div
                if div % 4 == 3 and count % 2 != 0:
                    return False
            
            div +=1
        return c % 4 != 3
