int longestIdealString(char* s, int k) {
    int dp[27] = {0};
    int n = strlen(s);

    for(int i = n -1;i >= 0;i--)
    {
        char cc = s[i];
        int id = cc- 'a';
        int maxi = -__INT_MAX__;

        int left = (id - k) > 0 ?(id - k) : 0;
        int right = (id + k) <26 ?(id + k) :26;

        for(int j = left; j<= right;j++)
        {
            maxi = maxi > dp[j] ? maxi : dp[j];
        }

        dp[id] = maxi + 1;
    }

    int max = -__INT_MAX__;
    for(int i =0;i < 27;i++)
    {
        if(dp[i] > max)
            max = dp[i];
    }
    return max;
}
