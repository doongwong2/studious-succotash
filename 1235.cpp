class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int numJobs = startTime.size();

        vector<tuple<int, int, int>>jobs(numJobs);

        for (int i = 0; i < startTime.size(); i++)
        {
            jobs[i] = { endTime[i], startTime[i], profit[i] };
        }

        sort(jobs.begin(), jobs.end());
        vector<int> dp(numJobs + 1);

        for (int i = 0; i < numJobs; i++)
        {
            auto [endTime, startTime, profit] = jobs[i];

            int latestJob = upper_bound(jobs.begin(), jobs.begin() + i, startTime, [&](int time, const auto& job) -> bool {return time < get<0>(job); }) - jobs.begin();

            dp[i + 1] = max(dp[i], dp[latestJob] + profit);

        }
        return dp[numJobs];
    }
};
