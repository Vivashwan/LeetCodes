class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        int oddSum = 0, evenSum = 0, count = 0;

        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                evenSum+=nums[i];
            }
            else oddSum+=nums[i];
        }

        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                evenSum-=nums[i];
            }
            else oddSum-=nums[i];
            
            if(evenSum==oddSum)
            {
                count++;
            }

            if(i%2)
            {
                evenSum+=nums[i];
            }
            else oddSum+=nums[i];
        }

        return count;
    }
};