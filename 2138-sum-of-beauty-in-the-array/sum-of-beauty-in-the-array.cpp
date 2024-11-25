class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();

        int preMax[n], sufMin[n];
        preMax[0] = nums[0], sufMin[n-1] = nums[n-1];

        for(int i=1; i<n; i++)
        {
            preMax[i] = max(preMax[i-1], nums[i]);
        }

        for(int j=n-2; j>=0; j--)
        {
            sufMin[j] = min(sufMin[j+1], nums[j]);
        }

        int sum=0;

        for(int i=1; i<n-1; i++)
        {
            if(preMax[i-1]<nums[i] && nums[i]<sufMin[i+1])
            {
                sum+=2;
            }
            else if(nums[i-1]<nums[i] && nums[i]<nums[i+1])
            {
                sum+=1;
            }
        }

        return sum;
    }
};