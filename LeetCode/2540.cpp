int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int common = -1;
    int n1 = 0, n2 = 0;

    while (n1 < nums1Size && n2 < nums2Size)
    {
        if (nums1[n1] == nums2[n2])
        {
            common = nums1[n1];
            break;
        }

        else if (nums1[n1] < nums2[n2])
            n1++;
        else
            n2++;
    }

    return common;
}
