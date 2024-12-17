class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int count = 0;

        for(int i=0; i<n; i++)
        {
            if(nums[i]==0)
            {
                count++;
            }
        }

        if(k >= count)
        {
            return n;
        }
        else
        {
            int i=0, j=0, count=0, maxim = INT_MIN;

            while(j<n)
            {
                if(nums[j]==0)
                {
                    count++;
                }
                while(count>k)
                {
                    if(nums[i]==0)
                    {
                        count--;
                    }

                    i++;
                }

                maxim = max(maxim, j-i+1);

                j++;
            }
            
            return maxim;
        }

    }
};