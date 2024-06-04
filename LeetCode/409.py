class Solution:
    def longestPalindrome(self, s: str) -> int:
        map = {}
        for c in s:
            if c in map:
                map[c] += 1
            else:
                map[c] = 1

        ans = 0
        isOdd = False

        for key in map:
            if map[key] % 2 == 0:
                ans += map[key]
            else:
                ans += map[key]
                if not isOdd:
                    isOdd = True
                else:
                    ans -= 1
        
        return ans

        
