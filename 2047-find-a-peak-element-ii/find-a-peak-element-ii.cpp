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
                if(mat[i][mid]>mat[maxRow][mid])
                {
                    maxRow=i;
                }
            }

            int leftNeighbor=mid-1>=0 ? mat[maxRow][mid-1]:-1;
            int rightNeighbor=mid+1<m ? mat[maxRow][mid+1]:-1;

            if(mat[maxRow][mid]>leftNeighbor && mat[maxRow][mid]>rightNeighbor)
            {
                return {maxRow, mid};
            }
            else if(mat[maxRow][mid]<leftNeighbor)
            {
                right=mid-1;
            }
            else left=mid+1;
        }

        return {-1, -1};
    }
};