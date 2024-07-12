class Solution {
private:
    void func(vector<vector<char>>& grid, vector<vector<int>>&adj, int n, int m, char ch)
    {
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(grid[i][j]==ch)
                {
                    adj[i][j] = 1;
                }

                if(i>0)
                {
                    adj[i][j]+=adj[i-1][j];
                }
                if(j>0)
                {
                    adj[i][j]+=adj[i][j-1];
                }
                if(i>0 && j>0)
                {
                    adj[i][j]-=adj[i-1][j-1];
                }
            }
        }
    }
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>>xCount(n, vector<int>(m, 0)), yCount(n, vector<int>(m, 0));

        func(grid, xCount, n, m, 'X');
        func(grid, yCount, n, m, 'Y');

        int ans = 0;

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                ans+=((xCount[i][j]==yCount[i][j])&&xCount[i][j]>0);
            }
        }

        return ans;
    }
};