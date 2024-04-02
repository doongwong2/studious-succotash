class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = { -1 };
        int ans = 0;
        const int m = 1e9 + 7;

        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= k; j++)
            {
                int ans = 0;
                for (int x = 0; x < min(i, j + 1); x++)
                {
                    ans += dp[i - 1][j - x];
                    ans %= m;
                }
                dp[i][j] = ans;
            }
        return dp[n][k];
    }
};
