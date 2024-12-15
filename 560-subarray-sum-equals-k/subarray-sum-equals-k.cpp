class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;

        int sum=0, ans=0;

        mp[sum]=1;

        for(auto it: nums)
        {
            sum+=it;

            int find1=sum-k;

            if(mp.find(find1)!=mp.end())
            {
                ans+=mp[find1];
            }

            mp[sum]++;
        }

        return ans;
    }
};