/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc(const void *a, const void *b)
{
    return (*(int*) a - *(int*) a);
}


int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    int *ans = (int*)malloc(sizeof(int)*1001);
    //ptr = (cast-type*)malloc(byte-size)

    for(int x = 0;x < 1000 ; x++)
        ans[x] = 0;

    qsort(deck,deckSize,sizeof(int),cmpfunc);
    //qsort(arr, number of elements, byte size, compare)


    int i =0; int j = 1;
    for(i,j;i < deckSize && j < deckSize;)
    {
        if(i < j)
        {
            ans[i] = deck[i];
            i += 2;
        }
        if( j < i)
        {
            ans[j] = deck[j];
            j += 2;
        } 
    }

    return ans;
}
