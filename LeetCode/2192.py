class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        ans = [[] for i in range(n)]
        child = [[] for i in range(n)]

        for i in edges:
            child[i[0]].append(i[1])
        for i in range(n):
            self.dfs(i, i, ans, child)
        return ans

    def dfs(self, x: int, curr: int, ans: List[List[int]], child: List[List[int]]) -> None:
        for i in child[curr]:
            if not ans[i] or ans[i][-1] != x:
                ans[i].append(x)
                self.dfs(x, i, ans, child)
        
