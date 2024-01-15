class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> no_lost, lost_once;
        map<int, int> mp;

        for (int i = 0; i < matches.size(); i++)
        {
            mp[matches[i][0]] += 0;
            mp[matches[i][1]] += 1;
        }

        for (std::map<int, int>::iterator i = mp.begin(); i != mp.end(); i++)
        {
            if (i->second == 0) no_lost.push_back(i->first);
            if (i->second == 1) lost_once.push_back(i->first);
        }
        ans.push_back(no_lost); ans.push_back(lost_once);
        return ans;

    }
};