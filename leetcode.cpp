class Solution {
public:
    int rob(vector<int>& nums) {
        int rob_prev1 = 0, rob_prev = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int temp = max(rob_prev1 + nums[i], rob_prev);
            rob_prev1 = rob_prev;
            rob_prev = temp;
        }
        return rob_prev;
    }
};