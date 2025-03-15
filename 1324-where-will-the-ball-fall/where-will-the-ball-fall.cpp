class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<int>res(m, -1);  

        for(int j=0; j<m; j++) 
        {
            int col=j;  

            for(int row=0; row<n; row++) 
            {
                int nextCol = col+grid[row][col]; 

                if(nextCol<0 || nextCol>=m || grid[row][col]!=grid[row][nextCol]) 
                {
                    col=-1;
                    break;
                }
                
                col=nextCol;
            }

            res[j] = col;
        }

        return res;
    }
};
