class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> tally;
        string ans;

        for (int i = 0; i < order.size(); i++)
            tally[order[i]] = 0;

        for (int i = 0; i < s.size(); i++)
            if (tally.find(s[i]) != tally.end())
                tally[s[i]]++;

        for (int i = 0; i < order.size(); i++)
            ans.append(tally[order[i]], order[i]);

        for (int i = 0; i < s.size(); i++)
            if (tally.find(s[i]) == tally.end())
                ans.push_back(s[i]);

        return ans;
    }
};