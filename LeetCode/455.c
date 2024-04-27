int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    int ans = 0;

    if(gSize == 0 || sSize == 0) return 0;

    qsort(g, gSize, sizeof(int), cmpfunc);
    qsort(s, sSize, sizeof(int), cmpfunc);

    int j =0;
    for(int i =0;i < gSize;i++)
    {
        while(j < sSize && s[j] < g[i]) j++;

        if( j >= sSize) break;

        if(g[i] <= s[j]){
            ans++;
            j++;
        }
    }
    return ans;
}
