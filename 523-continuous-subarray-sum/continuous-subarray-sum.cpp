class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>remainders;

        int sum=0, n=nums.size();
        remainders[0]=-1;

        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            int rem = sum%k;

            if(remainders.find(rem)!=remainders.end())
            {
                if(i-remainders[rem]>=2)
                {
                    return true;
                }
            }
            else remainders[rem] = i;
        }

        return false;
    }
};