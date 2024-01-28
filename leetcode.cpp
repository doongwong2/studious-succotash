class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int col = matrix[0].size();
        int row = matrix.size();

        for (int i = 0; i < row; i++)
            for (int j = 1; j < col; j++)
                matrix[i][j] += matrix[i][j - 1];

        int ans = 0;

        for (int i = 0; i < col; i++)
            for (int j = i; j < col; j++)
            {
                unordered_map<int, int> lookup;
                lookup[0] = 1;

                int sum = 0;

                for (int k = 0; k < row; k++)
                {
                    sum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    ans += lookup[sum - target];
                    lookup[sum]++;
                }
            }
        return ans;
    }
};