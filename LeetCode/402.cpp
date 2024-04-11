class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;

        for(int i =0;i < num.size();i++)
        {
            while(!stk.empty() && k > 0 && stk.top() > num[i])
            {
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }

        while(k > 0 && !stk.empty())
        {
            stk.pop();
            k--;
        }

        std::string res;
        while(!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(),res.end());

        size_t pos = res.find_first_not_of('0');
        res = (pos == std::string::npos) ? "0" : res.substr(pos);

        return res;
    }
};
