void sortColors(int* nums, int numsSize) {
    int w = 0, r = 0, b = numsSize -1;

    while ( w <= b)
    {
        if (nums[w] == 0)
        {
            int temp = nums[w];
            nums[w] = nums[r];
            nums[r] = temp;
            w++; r++;
        }
        else if (nums[w] == 1)
            w++;

        else
        {
            int temp = nums[w];
            nums[w] = nums[b];
            nums[b] = temp;
            b--;
        }
    }
}
