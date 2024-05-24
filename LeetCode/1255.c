int maxScoreWords(char** words, int wordsSize, char* letters, int lettersSize, int* score, int scoreSize) {
    int lettersCounter[26] ={0};
    for(int i =0;i < lettersSize;i++)
    {
        lettersCounter[letters[i] - 'a']++;
    }
    int totalScore = 0;

    void explore(int index, int* letterCounter, int currScore) 
    {
        if(currScore > totalScore) 
        {
            totalScore = currScore;
        }

        if(index == wordsSize) 
        {
            return;
        }

        for(int i = index;i < wordsSize; i++) 
        {
            int tmpCounter[26];
            memcpy(tmpCounter, letterCounter, 26 * sizeof(int));
            char *word = words[i];
            int wordScore = 0;
            bool isValid = true;

            for(int j = 0;word[j] != '\0';j++)
            {
                char ch = word[j];
                if(tmpCounter[ch - 'a'] > 0){
                    tmpCounter[ch - 'a']--;
                    wordScore += score[ch - 'a'];
                }
                else
                {
                    isValid = false;
                    break;
                }
            }

            if (isValid)
            {
                explore(i + 1, tmpCounter, currScore + wordScore);
            }
        }
    }

    explore(0, lettersCounter, 0);

    return totalScore;
}
