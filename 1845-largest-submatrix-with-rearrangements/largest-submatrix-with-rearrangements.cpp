class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();

        vector<int>height(m, 0);

        int maxim=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(matrix[i][j]==1)
                {
                    height[j]+=1;
                }
                else
                {
                    height[j]=0;
                }
            }

            vector<int>h=height;

            sort(h.begin(), h.end(), greater<int>());

            for(int j=0; j<m; j++)
            {
                if(h[j]==0)
                {
                    break;
                }

                maxim=max(maxim, h[j]*(j+1));
            }
        }

        return maxim;
    }
};