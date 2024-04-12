int max(int a, int b){
    if( a > b) return a;
    return b;
}

int min(int a, int b)
{
    if (a < b) return a;
    return b;
}

int trap(int* height, int heightSize) {
    if(heightSize == 0) return 0;

    int left[20005] ={0};
    int right[20005] = {0};

    left[0] = height[0];
    for(int i = 1;i < heightSize;i++)
        left[i] = max(left[i -1],height[i]);

    right[heightSize -1] = height[heightSize -1];
    for(int i = heightSize -2;i >= 0;i--)
        right[i] = max(right[i + 1],height[i]);

    int res = 0;

    for(int i = 0;i < heightSize;i++)
        res += min(left[i],right[i]) - height[i];
    
    return res;
}
