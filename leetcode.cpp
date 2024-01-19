class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int> > dp;
        vector<int> empty;

        int row = matrix.size();
        int column = matrix[0].size();

        for (int i = 0; i < column; i++)
            empty.push_back(INT_MIN);

        for (int i = 0; i < row; i++)
            dp.push_back(empty);

        for (int i = 0; i < column; i++)
            dp[0][i] = matrix[0][i];

        for (int i = 1; i < row; i++)
            for (int j = 0; j < column; j++)
            {
                if (j == 0) dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j + 1]);
                else if (j == row - 1) dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
                else dp[i][j] = matrix[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
            }

        return *min_element(dp[row - 1].begin(), dp[row - 1].end());
    }
};