class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long ret = -1, current = 0;

        if (nums.size() < 3) return -1;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
            current += nums[i];

        for (int i = nums.size() - 1; i > 0; i--)
        {
            if (current - nums[i] > nums[i])
            {
                ret = current;
            }
            else
            {
                current -= nums[i];
            }
        }
        return ret;
    }
};
