class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> left(n, -1), right(n, n);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();

            if (!s.empty())
                left[i] = s.top();

            s.push(i);
        }

        s = stack<int>();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && arr[s.top()] > arr[i])
                s.pop();

            if (!s.empty())
                right[i] = s.top();

            s.push(i);
        }

        long long ans = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            ans += static_cast<long long>(i - left[i]) * (right[i] - i) * arr[i] % mod;
            ans %= mod;
        }
        return ans;

    }
};
