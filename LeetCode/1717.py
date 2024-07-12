class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        a = 0
        b = 0
        min_ = min(x,y)
        res = 0

        for i in s:
            if i > 'b':
                res += min(a,b)*min_
                a = 0
                b = 0
            elif i == 'a':
                if x < y and b > 0:
                    b -= 1
                    res += y
                else:
                    a += 1

            elif i == 'b':
                if x > y and a > 0:
                    a -= 1
                    res += x
                else:
                    b += 1

        res += min(a,b) * min_
        return res

        
