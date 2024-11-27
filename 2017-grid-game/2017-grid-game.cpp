class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();

        vector<long long>f(n),s(n);

        for(int i=0; i<n; i++)
        {
            f[i]=grid[0][i];
            s[i]=grid[1][i];
        }

        for(int i=1; i<n; i++)
        {
            f[i]+=f[i-1];
            s[i]+=s[i-1];
        }

        long long ans=LLONG_MAX, maxi=LLONG_MIN;

        int blue=0, red=0;

        for(int i=0; i<n; i++)
        { 
            long long b1=f[n-1]-f[i], b2=(i-1>=0)?s[i-1]:0;

            maxi=max(b1,b2);
            ans=min(maxi,ans);
        }
        
        return ans;
    }
};