class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int>leftSum(n, 0), rightSum(n, 0);

        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            leftSum[i]=sum;
        } 

        sum=0;

        for(int i=n-1; i>=0; i--)
        {
            sum+=nums[i];
            rightSum[i]=sum;
        }

        for(int i=0; i<n; i++)
        {
            if(leftSum[i]==rightSum[i])
            {
                return i;
            }
        }

        return -1;
    }
};