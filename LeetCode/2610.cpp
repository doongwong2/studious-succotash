class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>>ans;
        unordered_map<int, int>map;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++)
            map[nums[i]]++;

        for (auto i : map)
            maxi = max(maxi, i.second);

        for (int j = 0; j < maxi; j++)
        {
            vector<int> temp;

            for (auto& i : map)
            {
                if (i.second > 0)
                {
                    temp.push_back(i.first);
                    i.second--;
                }
            }

            ans.push_back(temp);
        }
        return ans;
    }
};
