/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc(const void *a, const void *b)
{
    return (*(int*) a - *(int*) b);
}


int* deckRevealedIncreasing(int* deck, int deckSize, int* ans) {
    ans = (int*)malloc(sizeof(int)*deckSize);
    //ptr = (cast-type*)malloc(byte-size)

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

    for(i = 0;i < deckSize;i++)
        printf("%d\n",ans[i]);

    return &ans;
}
