class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();

        int mini=INT_MAX, negCount=0;
        long long sum=0;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                sum+=abs(matrix[i][j]);

                if(matrix[i][j]<0)
                {
                    negCount++;
                }

                mini=min(mini, abs(matrix[i][j]));
            }
        }

        return negCount%2==0 ? sum : sum-2*mini;
    }
};