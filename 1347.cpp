class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> m;
        int i = 0;
        for (i = 0; i < s.length(); i++) m[s[i] - 'a']++;

        for (i = 0; i < t.length(); i++) m[t[i] - 'a']--;

        int ans = 0;

        for (i = 0; i < m.size(); i++) ans += abs(m[i]);

        return ans / 2;
    }
};
