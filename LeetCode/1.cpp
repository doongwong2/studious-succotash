class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> h;
        for(int i =0;i < nums.size();i++)
        {
            int c = target - nums[i];
            if(h.find(c) != h.end()){
                return {h[c],i};
            }
            h[nums[i]] = i;
        }
        return {};
    }
};
