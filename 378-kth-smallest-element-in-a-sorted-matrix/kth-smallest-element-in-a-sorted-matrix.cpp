class Solution {
private:
    int midIsGreaterThan(int mid, vector<vector<int>>& matrix, int n)
    {
        int row=0, col=n-1, count=0;

        while(row<n && col>=0)
        {
            if(matrix[row][col]<=mid)
            {
                count+=(col+1);
                row++;
            }
            else col--;
        }

        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();

        int low=matrix[0][0], high=matrix[n-1][n-1];

        int res=0;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(midIsGreaterThan(mid, matrix, n)>=k)
            {
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        
        return res;
    }
};