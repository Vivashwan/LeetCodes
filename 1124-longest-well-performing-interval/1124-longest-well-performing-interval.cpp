class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int maxim=0;

        unordered_map<int, int>mp;

        int n=hours.size(), sum=0;

        for(int right=0; right<n; right++)
        {
            sum+=hours[right]>8 ? 1:-1;

            if(sum>0)
            {
                maxim=right+1;
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