class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;

        unordered_map<int, int>map;
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }

        for (int i = 0; i < map.size(); i++)
        {
            int temp = map[i];
            if (temp == 1)
                return -1;

            count += (temp + 2) / 3;
        }
        return count;
    }
};
