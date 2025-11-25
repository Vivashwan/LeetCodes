class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();

        unordered_map<int, int>mp;

        int maxim=0;

        int sum=0;

        for(int right=0; right<n; right++)
        {
            sum+=hours[right]>=9 ? 1:-1;

            if(sum>0)
            {
                maxim=max(maxim, right+1);
            }
            else
            {
                if(mp.find(sum-1)!=mp.end())
                {
                    maxim=max(maxim, right-mp[sum-1]);
                }
            }

            if(mp.find(sum)==mp.end())
            {
                mp[sum]=right;
            }
        }

        return maxim;
    }
};