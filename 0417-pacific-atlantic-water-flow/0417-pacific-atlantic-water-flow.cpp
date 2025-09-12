class Solution {
private:
    void dfs(int i, int j, int n, int m, vector<vector<bool>>&visited, vector<vector<int>>&heights)
    {
        visited[i][j]=true;

        int dir[5]={-1, 0, 1, 0, -1};

        for(int k=0; k<4; k++)
        {
            int newX=i+dir[k], newY=j+dir[k+1];

            if(newX>=0 && newX<n && newY>=0 && newY<m && !visited[newX][newY] && heights[newX][newY]>=heights[i][j])
            {
                dfs(newX, newY, n, m, visited, heights);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();

        vector<vector<bool>>pacific(n, vector<bool>(m, false));
        vector<vector<bool>>atlantic(n, vector<bool>(m, false));

        for(int i=0; i<n; i++)
        {
            dfs(i, 0, n, m, pacific, heights);
            dfs(i, m-1, n, m, atlantic, heights);
        }

        for(int j=0; j<m; j++)
        {
            dfs(0, j, n, m, pacific, heights);
            dfs(n-1, j, n, m, atlantic, heights);
        }

        vector<vector<int>>res;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};