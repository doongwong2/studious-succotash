class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive, negative, result;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0) positive.push_back(nums[i]);
            if (nums[i] < 0) negative.push_back(nums[i]);
        }

        for (int i = 0; i < positive.size(); i++)
        {
            result.push_back(positive[i]);
            result.push_back(negative[i]);
        }

        return result;
    }
};