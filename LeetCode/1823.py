class Solution:
    def findTheWinner(self, n: int, k: int) -> int:
        circle = [i for i in range(1, n + 1,1)]
        idx = 0

        while len(circle) != 1:
            remove = (idx + k - 1) % len(circle)
            circle.pop(remove)
            idx = remove

        return circle[0]

        
