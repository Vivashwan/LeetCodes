class Solution {
private:
    int MOD = 1e9+7;

    vector<vector<int>>adj = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};

    int func(int n, int cell, vector<vector<int>>&dp)
    {
        if(n==0)
        {
            return 1;
        }

        if(dp[n][cell]!=-1)
        {
            return dp[n][cell];
        }

        int res=0;

        for(auto it: adj[cell])
        {
            res=(res+func(n-1, it, dp))%(MOD);
        }

        return dp[n][cell] = res;
    }
public:
    int knightDialer(int n) {
        vector<vector<int>>dp(5001, vector<int>(10, -1));

        int res=0;

        for(int cell=0; cell<=9; cell++)
        {
            res=(res+func(n-1, cell, dp))%MOD;
        }

        return res;
    }
};