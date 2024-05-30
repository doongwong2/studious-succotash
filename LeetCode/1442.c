int countTriplets(int* arr, int arrSize) {
    int count = 0;

    for(int i = 0;i < arrSize;i++)
        for(int j = i + 1;j < arrSize;j++)
        {
            int a = 0;
            for(int k =i;k < j;k++)
                a^=arr[k];

            int b = 0;
            for(int k = j;k < arrSize;k++)
            {
                b ^= arr[k];
                if( a == b) count++;
            }
        }

    return count;
}
