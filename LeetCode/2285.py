class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        res = 0
        cost = 1
        con = [0] * n

        for i in roads:
            con[i[0]] += 1
            con[i[1]] += 1

        con.sort()

        for i in con:
            res += i *cost
            cost += 1

        return res
        
