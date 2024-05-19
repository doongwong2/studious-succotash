typedef struct {
    long long first;
    long long second;
} pair;

long long maximumValueSum(int* nums, int numsSize, int k, int** edges, int edgesSize, int* edgesColSize) {
    pair *dp = calloc(numsSize + 1,sizeof(pair));
    dp[numsSize].first = 0;
    dp[numsSize].second = INT_MIN;

    for(int i = numsSize -1; i >= 0; i--)
    {
        dp[i].first = fmax(
            dp[i + 1].second + (nums[i] ^ k),
            dp[i + 1].first + nums[i]
        );

        dp[i].second = fmax(
            dp[i + 1].first + (nums[i] ^ k),
            dp[i + 1].second + nums[i]
        );
    }
    return dp[0].first;
}
