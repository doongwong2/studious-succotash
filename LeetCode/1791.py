class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        for i in edges:
            if i[0] in edges[1]:
                return i[0]
            else:
                return i[1]
