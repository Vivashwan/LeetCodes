class Solution {
private:
    int func(string& s1, string& s2, int n, int m, int ind1, int ind2, vector<vector<int>>&dp)
    {
        if(ind1>=n || ind2>=m)
        {
            if(ind1==n and ind2==m)
            {
                return 0;
            }
            else if(ind1>=n)
            {
                int sum=0;

                for(int i=ind2; i<m; i++)
                {    
                    sum+=int(s2[i]);
                }

                return sum;
            }
            else
            {
                int sum=0;

                for(int i=ind1; i<n; i++)
                {    
                    sum+=int(s1[i]);
                }

                return sum;
            }
        }

        if(dp[ind1][ind2]!=-1)
        {
            return dp[ind1][ind2];
        }

        int res=0;

        if(s1[ind1]==s2[ind2])
        {
            res=func(s1, s2, n, m, ind1+1, ind2+1, dp);
        }
        else res=min(int(s1[ind1])+func(s1, s2, n, m, ind1+1, ind2, dp), int(s2[ind2])+func(s1, s2, n, m, ind1, ind2+1, dp));

        return dp[ind1][ind2] = res;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length(), m=s2.length();

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

        return func(s1, s2, n, m, 0, 0, dp);
    }
};