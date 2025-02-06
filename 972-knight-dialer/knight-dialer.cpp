class Solution {
private:
    int MOD = 1e9+7;

    vector<vector<int>>adj = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};

    void func(int n, vector<vector<int>>&dp)
    {
        for(int cell=0; cell<=9; cell++)
        {
            dp[0][cell]=1;
        }

        for(int i=1; i<n; i++)
        {
            for(int cell=0; cell<=9; cell++)
            {
                int res=0;

                for(auto it: adj[cell])
                {
                    res=(res+dp[i-1][it])%(MOD);
                }

                dp[i][cell] = res;
            }
        }

        return;
    }
public:
    int knightDialer(int n) {
        vector<vector<int>>dp(5002, vector<int>(11, 0));

        int res=0;

        func(n, dp);

        for(int cell=0; cell<=9; cell++)
        {
            res=(res+dp[n-1][cell])%MOD;
        }

        return res;
    }
};