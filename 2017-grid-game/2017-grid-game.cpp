class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n=grid[0].size();

        vector<long long>firstRow(n), secondRow(n);

        for(int i=0; i<n; i++)
        {
            firstRow[i]=grid[0][i];
            secondRow[i]=grid[1][i];
        }

        for(int i=1; i<n; i++)
        {
            firstRow[i]+=firstRow[i-1];
            secondRow[i]+=secondRow[i-1];
        }

        long long res=LLONG_MAX;

        for(int i=0; i<n; i++)
        {
            long long pathFollowed= i>0 ? secondRow[i-1] : 0,
            pathToFollow=firstRow[n-1]-firstRow[i];

            long long maxi=max(pathFollowed, pathToFollow);

            res=min(maxi, res); 
        }

        return res;

    }
};