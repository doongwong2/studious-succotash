class Solution:
    def reverseParentheses(self, s: str) -> str:
        res = []
        ind_stack = deque()

        for i in s:
            if i == "(":
                ind_stack.append(len(res))
            elif i == ")":
                start = ind_stack.pop()
                res[start:] = res[start:][::-1]
            else:
                res.append(i)

        return ''.join(res)        
