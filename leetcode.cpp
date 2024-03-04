int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int bagOfTokensScore(int* tokens, int tokensSize, int power) {
    qsort(tokens, tokensSize, sizeof(int), compare);
    int score = 0, maxS = 0, left = 0, right = tokensSize - 1;

    while (left <= right)
    {
        if (power >= tokens[left])
        {
            power -= tokens[left];
            score++;
            left++;
            if (score > maxS) maxS = score;
        }
        else if (score > 0)
        {
            power += tokens[right];
            score--;
            right--;
        }
        else break;
    }
    return maxS;
}

