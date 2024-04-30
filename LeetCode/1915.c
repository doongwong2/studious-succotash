long long wonderfulSubstrings(char * word){
    long long count = 0;
    int freq[1024] = {1};

    int bitmask = 0;
    int masks[10] = {1,2,4,8,16,32,64,128,256,512};
    int len = strlen(word);

    for(int i =0;i < len;i++)
    {
        bitmask ^= masks[word[i] - 'a'];
        count += freq[bitmask];
        for(int j = 0;j <10;j++)
        {
            int complement = bitmask ^ masks[j];
            count += freq[complement];
        }
        freq[bitmask]++;
    }
    return count;

}
