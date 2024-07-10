class Solution:
    def minOperations(self, logs: List[str]) -> int:
        res = 0

        for i in logs:
            if i == "../":
                res -= 1 if res > 0 else 0
            elif i != "./":
                res += 1

        return res
