int minOperations(int* nums, int numsSize, int k) {
    int xorSum = 0;
    for(register int i = 0;i < numsSize;i++)
        xorSum^= nums[i];
    return __builtin_popcount(xorSum^k);
}
