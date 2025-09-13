class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));

        queue<pair<int, int>>q;

        for(int i=0; i<n; i++) 
        {
            for(int j=0; j<m; j++) 
            {
                if(mat[i][j]==0) 
                {
                    dist[i][j]=0;
                    q.push({i, j});
                }
            }
        }

        int dirX[4]={-1, 0, 0, 1}, dirY[4]={0, -1, 1, 0};

        while(!q.empty()) 
        {
            auto [row, col]=q.front();
            q.pop();

            for(int k=0; k<4; k++) 
            {
                int newRow=row+dirX[k], newCol=col+dirY[k];

                if(newRow>=0 && newRow<n && newCol>=0 && newCol<m) 
                {
                    if(dist[newRow][newCol]>dist[row][col]+1) 
                    {
                        dist[newRow][newCol]=dist[row][col]+1;
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return dist;
    }
};
