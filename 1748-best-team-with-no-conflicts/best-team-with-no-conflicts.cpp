class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();

        vector<int>dp(n, 0);

        vector<pair<int, int>>arr(n, {0, 0});

        for(int i=0; i<n; i++)
        {
            arr[i].first=ages[i];
            arr[i].second=scores[i];
        }

        sort(arr.begin(), arr.end());

        int score=0;

        for(int i=0; i<n; i++)
        {
            dp[i]=arr[i].second;

            for(int j=i-1; j>=0; j--)
            {
                if(arr[i].second>=arr[j].second)
                {
                    dp[i]=max(dp[i], dp[j]+arr[i].second);
                }
            }

            score=max(score, dp[i]);
        }

        return score;
    }
};