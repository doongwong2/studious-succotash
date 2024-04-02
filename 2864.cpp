class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '1') one++;
        }

        s[s.size() - 1] = '1';
        one--;

        int i = 0;
        for (i; one > 0; i++, one--)
            s[i] = '1';

        for (i; i < s.size() - 1; i++)
            s[i] = '0';

        return s;
    }
};
