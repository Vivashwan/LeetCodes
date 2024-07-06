class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), res=0;

        while(true)
        {
            int evenCount=0, countZero=0;

            for(int i=0; i<n; i++)
            {
                if(nums[i]%2!=0)
                {
                    nums[i]-=1;
                    res++;
                }
                else evenCount++;

                if(nums[i]==0)
                {
                    countZero++;
                }
            }

            if(countZero==n)
            {
                return res;
            }

            if(evenCount==n)
            {
                res++;

                for(int i=0; i<n; i++)
                {
                    nums[i]/=2;
                }
            }
        }

        return res;
    }
};