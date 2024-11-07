class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();

        vector<vector<long long>>dp(n, vector<long long>(m, -1));

        for(int j=0; j<m; j++)
        {
            dp[0][j] = points[0][j];
        }

        for(int i=1; i<n; i++)
        {
            vector<long long>left(m, -1), right(m, -1);

            left[0] = dp[i-1][0];

            for(int k=1; k<m; k++)
            {
                left[k] = max(left[k-1],dp[i-1][k]+k);
            }

            right[m-1] = dp[i-1][m-1]-(m-1);

            for(int k=m-2; k>=0; k--)
            {
                right[k] = max(right[k+1], dp[i-1][k]-k);
            }

            for(int j=0; j<m; j++)
            {
                dp[i][j] = max(left[j]-j, right[j]+j) + points[i][j];
            }
        }

        long long res = -1;

        for(auto it: dp[n-1])
        {
            res = max(res, it);
        }

        return res;
    }
};