class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        vector<int> frec;
        int ret = 0;

        for (int i = 0; i < arr.size(); i++)
            mp[arr[i]]++;
        std::unordered_map<int, int>::iterator it;

        for (it = mp.begin(); it != mp.end(); it++)
            frec.push_back(it->second);

        sort(frec.begin(), frec.end());

        for (int i = 0; i < frec.size(); i++)
        {
            if (k > frec[i])
            {
                k -= frec[i];
                frec[i] = 0;
            }
            else
            {
                frec[i] -= k;
                k = 0;
            }
            if (frec[i] != 0) ret++;
        }
        return ret;
    }
};
