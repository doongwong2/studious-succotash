int minimumLength(char* s) {
    int right = 0, left = 0;
    while (s[right] != '\0')
    {
        right++;
    }

    right--;
    while (left < right && s[left] == s[right])
    {
        char c = s[left];
        while (left <= right && s[left] == c)
            left++;

        while (right >= left && s[right] == c)
            right--;
    }
    return right - left + 1;
}