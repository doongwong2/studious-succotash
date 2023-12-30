class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if (words.size() == 1)
            return true;

        int totalCharCount = 0;
        for (const string& s : words)
        {
            totalCharCount += s.length();
        }

        if (totalCharCount % words.size() != 0)
            return false;

        vector<int>aMap(26, 0);
        for (const string& s : words)
        {
            for (char c : s) {
                aMap[c - 'a']++;
            }
        }

        for (int i : aMap)
        {
            if (i % words.size() != 0)
                return false;
        }

        return true;
    }
};