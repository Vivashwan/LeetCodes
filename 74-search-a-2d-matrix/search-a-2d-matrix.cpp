class Solution {
private:
    bool isPresent(vector<int>&matrix, int low, int high, int target)
    {
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(matrix[mid]==target)
            {
                return true;
            }
            else if(matrix[mid]>target)
            {
                high=mid-1;
            }
            else low=mid+1;
        }

        return false;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();

        for(int i=0; i<n; i++)
        {
            if(matrix[i][m-1]==target)
            {
                return true;
            }
            else if(matrix[i][m-1]>target)
            {
                if(isPresent(matrix[i], 0, m-1, target))
                {
                    return true;
                }
                else break;
            }
        }

        return false;
    }
};