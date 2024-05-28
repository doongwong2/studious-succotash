int equalSubstring(char* s, char* t, int maxCost) {
    int n = strlen(s);
    int left = 0;
    int current_cost = 0;
    int max_length = 0;

    for(int right = 0;right < n;right++)
    {
        current_cost += abs(s[right] - t[right]);

        while(current_cost > maxCost)
        {
            current_cost -= abs(s[left] - t[left]);
            left++;
        }

        max_length = fmax(max_length, right - left + 1);
    }
    return max_length;
}
