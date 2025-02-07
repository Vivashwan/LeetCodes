class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n = arr.size();

        unordered_map<int, int>mp;

        int res=1;

        for(int i=0; i<n; i++)
        {
            int val = arr[i];

            if(mp.find(val-diff)!=mp.end())
            {
                mp[val] = mp[val-diff]+1;
            }
            else mp[val] = 1;

            res = max(res, mp[val]);
        }

        return res;
    }
};