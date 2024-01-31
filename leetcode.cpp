class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<int> stuck;

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!stuck.empty() && temperatures[stuck.top()] < temperatures[i])
            {
                ret[stuck.top()] = i - stuck.top();
                stuck.pop();
            }

            stuck.push(i);
        }

        return ret;
    }
};