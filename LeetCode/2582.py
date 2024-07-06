class Solution:
    def passThePillow(self, n: int, time: int) -> int:
        pos = 1
        timeNow = 0
        direction = 1

        while timeNow < time:
            if 0 < pos + direction <= n:
                pos += direction
                timeNow += 1

            else:
                direction *= -1
            
        return pos
        
