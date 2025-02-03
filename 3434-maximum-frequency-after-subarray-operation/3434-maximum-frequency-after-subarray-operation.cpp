class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        int count=0, ans;

        for(auto it: nums)
        {
            if(it==k)
            {
                count++;
            }
        }
        
        ans=count;

        for(int val=1; val<=50; val++)
        {
            if(val==k)
            {
                continue;
            }

            int change=0, maxim = 0;

            for(auto it: nums)
            {
                if(it==val)
                {
                    change++;
                }
                else if(it==k)
                {
                    change--;
                }

                if(change<0)
                {
                    change=0;
                }

                maxim = max(maxim, change);
            }        

            ans = max(ans, count+maxim);
        }

        return ans;
    }
};