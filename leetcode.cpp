class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int tally = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            tally++;
        }

        return left << tally;
    }
};