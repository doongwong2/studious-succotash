int openLock(char** deadends, int deadendsSize, char* target) {
    char visited[10000] = {0};
    for(int i =0;i < deadendsSize ;i++)
        visited[atoi(deadends[i])] = 1;
    
    if(visited[0])
        return -1;

    int targetVal = atoi(target);
    int queue[10000], front = 0, rear = 1;
    queue[0] = 0;
    visited[0] = 1;
    int steps = 0;
    while(front < rear){
        int size = rear - front;
        for(int i= 0;i < size;i++)
        {
            int lock = queue[front++];
            if(lock == targetVal)
                return steps;
        
            for(int j = 1;j <= 1000; j *= 10)
            {
                int digit = (lock/j) % 10;
                for(int k = -1; k <= 1;k +=2)
                {
                    int newDigit = (digit + k + 10) % 10;
                    int newLock = lock + (newDigit - digit) * j;
                    if(!visited[newLock]){
                        visited[newLock] = 1;
                        queue[rear++] = newLock;
                    }
                }
            }
        }
        steps++;

    }
    return -1;
}
