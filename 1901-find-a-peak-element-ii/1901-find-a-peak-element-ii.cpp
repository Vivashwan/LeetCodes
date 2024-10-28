class Solution {
private: 
    int maxElement(vector<vector<int>>& mat, int n, int m, int col)
    {
        int maxVal = -1, ind = -1;

        for(int i=0; i<n; i++)
        {
            if(mat[i][col]>maxVal)
            {
                maxVal = mat[i][col];
                ind = i;
            }
        }

        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int low = 0, high = m-1;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            int row = maxElement(mat, n, m, mid);

            int left = mid-1>=0 ? mat[row][mid-1]:-1;
            int right = mid+1<m ? mat[row][mid+1]:-1;

            if(mat[row][mid]>left && mat[row][mid]>right)
            {
                return {row, mid};
            }
            else if(mat[row][mid]<left)
            {
                high = mid-1;
            }
            else low = mid+1;
        }   

        return {-1, -1};
    }
};