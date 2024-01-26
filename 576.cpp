typedef long long ll;

class Solution {
public:
    int moves[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
    const int mod = 1e9 + 7;
    int dp[2][51][51] = { 0 };

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        for (int k = 1; k <= maxMove; k++)
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                {
                    ll ans = 0;
                    for (int x = 0; x < 4; x++)
                    {
                        int ni = i + moves[x][0];
                        int nj = j + moves[x][1];

                        if (ni < 0 || ni >= m || nj < 0 || nj >= n) ans++;

                        else ans += dp[(k - 1) & 1][ni][nj];
                    }
                    dp[k & 1][i][j] = ans % mod;
                }

        return dp[maxMove & 1][startRow][startColumn];
    }
};
