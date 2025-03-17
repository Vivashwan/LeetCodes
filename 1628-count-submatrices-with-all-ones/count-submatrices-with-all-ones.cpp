class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>>prefix(m, vector<int>(n, 0));
        
        for(int i=0; i<m; i++) 
        {
            for(int j=0; j<n; j++) 
            {
                if(mat[i][j]==1) 
                {
                    prefix[i][j] = (j==0) ? 1 : prefix[i][j-1] + 1;
                }
            }
        }
        
        int count=0;
        
        for (int j=0; j<n; j++) 
        {
            for(int i=0; i<m; i++) 
            {
                int minWidth=prefix[i][j];

                for(int k=i; k>=0 && minWidth>0; k--) 
                {
                    minWidth = min(minWidth, prefix[k][j]);
                    count += minWidth;
                }
            }
        }
        
        return count;
    }
};