class Solution {
public:
    int climbStairs(int n) {
        int now = 1, previous = 1, previous1;
        for (int i = 1; i < n; i++)
        {
            previous1 = previous;
            previous = now;
            now = previous + previous1;
        }
        return now;
    }
};
