class Solution {
private:
    int func(int n, vector<int>&nums)
    {
        int pick=0, notPick=0;
        int curr=0, prev1=0, prev2=0;

        for(int ind=n-1; ind>=0; ind--)
        {
            pick = nums[ind] + ((ind+2 < n+1) ? prev2:0);

            notPick = prev1;

            curr=max(pick, notPick);

            prev2=prev1;
            prev1=curr;
        }

        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        return func(n, nums);
    }
};