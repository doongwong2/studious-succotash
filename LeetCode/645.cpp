class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> arr(nums.size() + 1, 0);
        vector<int> fix;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            arr[nums[i]]++;
        }

        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
            {
                fix.push_back(nums[i]);

                for (int j = 1; j < arr.size(); j++)
                {
                    if (arr[j] == 0) fix.push_back(j);
                }
            }

        }

        return fix;

    }
};
