class Solution {
private:
    int MOD = 1e9+7;

    int rev(int num)
    {
        int ans = 0;

        while(num!=0)
        {
            int rem = num%10;
            ans =ans*10 + rem;

            num/=10;
        }

        return ans;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int>mp;

        int count=0;

        for(auto it: nums)
        {
            count = (count+mp[it-rev(it)]++)%MOD;
        }

        return count;
    }
};