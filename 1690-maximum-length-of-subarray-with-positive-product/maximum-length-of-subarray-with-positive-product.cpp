class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int pos = 0, neg = 0, ans = 0;

        for(auto it: nums)
        {
            if(it==0)
            {
                pos = 0, neg = 0;
            }
            else if(it>0)
            {
                pos++;
            }
            else neg++;

            if(neg%2==0)
            {
                ans = max(ans, pos+neg);
            }
        }

        pos = 0, neg = 0;

        for(int i = nums.size()-1; i>=0; --i)
        {
            if(nums[i]==0)
            {
                pos = 0, neg = 0;
            }
            else if(nums[i]>0)
            {
                pos++;
            }
            else neg++;

            if(neg%2==0)
            {
                ans = max(ans, pos+neg);
            }
        }

        return ans;
    }
};