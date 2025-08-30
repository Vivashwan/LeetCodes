class Solution {
private:
    int MOD=1e9+7;
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();

        vector<int>prefix(n, 0);

        for(auto it: requests)
        {
            prefix[it[0]]++;

            if(it[1]+1<n)
            {
                prefix[it[1]+1]--;
            }
        }

        for(int i=1; i<n; i++)
        {
            prefix[i]+=prefix[i-1];
        }

        sort(nums.begin(), nums.end());
        sort(prefix.begin(), prefix.end());

        long long res=0;

        for(int i=0; i<n; i++)
        {
            res=(res+((long long)nums[i]*prefix[i]))%MOD;
        }

        return res%MOD;
    }
};