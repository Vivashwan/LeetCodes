class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(), m=image[0].size();

        int oldColor=image[sr][sc];

        if(oldColor==color)
        {
            return image;
        }

        queue<pair<int, int>>q;

        q.push({sr, sc});

        while(!q.empty())
        {
            auto [x, y]=q.front();
            q.pop();

            image[x][y]=color;

            vector<int>dirX={-1, 0, 0, 1};
            vector<int>dirY={0, -1, 1, 0};

            for(int i=0; i<4; i++)
            {
                int newX=dirX[i]+x, newY=dirY[i]+y;

                if(newX>=0 && newX<n && newY>=0 && newY<m && image[newX][newY]==oldColor)
                {
                    q.push({newX, newY});
                }
            }  
        }

        return image;
    }
};