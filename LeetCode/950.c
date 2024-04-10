/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmpfunc(const void *a, const void *b)
{
    return (*(int*) a - *(int*) b);
}

int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize) {
    qsort(deck,deckSize,sizeof(int),cmpfunc);
    
    int* cirArray = (int*)malloc(sizeof(int) * deckSize);
    for (int i = 0; i < deckSize; i++) {
        cirArray[i] = i;
    }

    int front = 0,rear = deckSize - 1;
    
    int* result = (int*)malloc(sizeof(int) * deckSize);
    
    for (int i = 0; i < deckSize; i++) {
        result[cirArray[front]] = deck[i];
        front = (front + 1) % deckSize;
        if (front != rear) {
            rear = (rear + 1) % deckSize;
            cirArray[rear] = cirArray[front];
            front = (front + 1) % deckSize;
        }
    }
    
    *returnSize = deckSize;
    
    free(cirArray);
    
    return result;
}

