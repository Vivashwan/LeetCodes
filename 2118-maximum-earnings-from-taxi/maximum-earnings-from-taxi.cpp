class Solution {
private:
    long long func(int curr, unordered_map<long long, vector<pair<long long, long long>>>&mp,  vector<long long>&dp, int &n)
    {
        if(curr==n)
        {
            return 0;
        }

        if(dp[curr]!=-1)
        {
            return dp[curr];
        }

        if(mp[curr].size()>0)
        {
            long long pick = INT_MIN;

            for(int i=0; i<mp[curr].size(); i++)
            {
                auto p = mp[curr][i];

                long long start = curr, end = p.first, tip = p.second;

                long long temp = (end-start+tip) + func(end, mp, dp, n);

                pick = max(pick, temp);
            }

            long long notPick = 0 + func(curr+1, mp, dp, n);
            return dp[curr] = max(notPick, pick);
        }
        else return dp[curr] = 0 + func(curr+1, mp, dp, n);

        return 0;
    }
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        unordered_map<long long, vector<pair<long long, long long>>>mp;

        vector<long long>dp(n+1, -1);

        for(auto it: rides)
        {
            mp[it[0]].push_back({it[1], it[2]});
        }

        return func(1, mp, dp, n);
    }
};