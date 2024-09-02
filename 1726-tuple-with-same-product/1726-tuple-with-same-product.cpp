class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<long long, int>mp;

        int n = nums.size(), count=0;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                long long prod = (long long)(nums[i]*nums[j]);

                mp[prod]++;
            }
        }

        for(auto it: mp)
        {
            int freq = it.second;
            if(freq>1)
            {
                count+=(freq * (freq - 1)) / 2 * 8;
            }
        }

        return count;
    }
};