class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();

        if(n==0 || m==0)
        {
            return false;
        }

        int row=0, col=m-1;

        while(row<n && col>=0)
        {
            if(matrix[row][col]==target)
            {
                return true;
            }
            else if(matrix[row][col]>target)
            {
                col--;
            }
            else row++;
        }

        return false;
    }
};