class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++)
        {
            if (!stk.empty() && abs(s[i] - stk.top()) == 32)
                stk.pop();
            else
                stk.push(s[i]);
        }

        string res;
        while (!stk.empty())
        {
            res = stk.top() + res;
            stk.pop();
        }

        return res;
    }
};
