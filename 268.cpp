/*the better solution.*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int actualSum = (n * (n + 1)) / 2;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }

        return actualSum - sum;
    }
};

/*My brute force solution.*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != ans) break;
            ans++;
        }
        return ans;
    }
};
