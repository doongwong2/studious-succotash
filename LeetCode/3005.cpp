int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

int maxFrequencyElements(int* nums, int numsSize) {
    int freq[105] = { 0 };
    int maxi = 0, maxj = 0;

    for (int i = 0; i < numsSize; i++)
    {
        freq[nums[i]]++;
        maxi = max(maxi, freq[nums[i]]);
    }

    for (int i = 1; i <= 100; i++)
    {
        if (freq[i] == maxi) maxj += maxi;
    }

    return maxj;
}
