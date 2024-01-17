class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int> tally;

        for (int i = 0; i < arr.size(); i++)
        {
            int count = 1;
            for (i; i + 1 < arr.size() && arr[i] == arr[i + 1]; i++)
                count++;

            tally.push_back(count);
        }

        sort(tally.begin(), tally.end());

        for (int i = 1; i < tally.size(); i++)
            if (tally[i] == tally[i - 1]) return false;

        return true;
    }
};