class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();

        int left=0, right=m-1;

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            int maxRow=0;

            for(int i=0; i<n; i++)
            {
                if(mat[maxRow][mid]<mat[i][mid])
                {
                    maxRow=i;
                }
            }

            int leftNeighbor=(mid-1>=0) ? mat[maxRow][mid-1]:-1;
            int rightNeighbor=(mid+1<m) ? mat[maxRow][mid+1]:-1;

            if(leftNeighbor<mat[maxRow][mid] && rightNeighbor<mat[maxRow][mid])
            {
                return {maxRow, mid};
            }
            else if(leftNeighbor>mat[maxRow][mid])
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }

        return {-1, -1};
    }
};