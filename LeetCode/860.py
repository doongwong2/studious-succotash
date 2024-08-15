class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        n = len(bills)
        change = [0,0]
        for i in range(n):
            if bills[i] == 5:
                change[0] += 1
            elif bills[i] == 10 and change[0] > 0:
                change[1] += 1
                change[0] -= 1
            elif bills[i] == 20 and change[0] > 0 and change[1] > 0:
                change[0] -= 1
                change[1] -= 1
            elif bills[i] == 20 and change[0] >2:
                change[0] -= 3
            else: return False

        return True
        
