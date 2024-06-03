class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        s_index, t_index = 0, 0
        s_len, t_len = len(s), len(t)

        while s_index < s_len and t_index < t_len:
            if s[s_index] == t[t_index]:
                t_index += 1
            s_index += 1

        return t_len - t_index
        
