class Solution {
private:
    const int MOD=1e9+7;
    vector<vector<int>>dp;

    int func(int pos, int endPos, int k) 
    {
        if(k==0)
        { 
            return pos==endPos;
        }

        if(abs(pos-endPos)>k)
        { 
            return 0;
        }

        if(dp[pos+1000][k]!=-1)
        { 
            return dp[pos+1000][k];
        }

        long long left=func(pos-1, endPos, k-1), right=func(pos+1, endPos, k-1);

        return dp[pos+1000][k]=(left+right)%MOD;
    }

public:
    int numberOfWays(int startPos, int endPos, int k) {
        dp.assign(4005, vector<int>(k+1, -1));
        return func(startPos, endPos, k);
    }
};
