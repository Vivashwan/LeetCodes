class Solution {
private:
    int MOD = 1e9+7;
public:
    int countPairs(vector<int>& nums) {
        int n = nums.size(), count = 0;

        unordered_map<int, int>mp;

        for(int i=0; i<n; i++)
        {
            int pow = 1;

            for(int j=0; j<=21; j++)
            {
                if(mp.count(pow-nums[i]))
                {
                    count+=mp[pow-nums[i]];
                    count%=MOD;
                }
                pow*=2;
            }

            mp[nums[i]]++;
        }

        return count;
    }
};