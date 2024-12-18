class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();

        vector<int>prefix(n, 0);

        for(int i=0; i<n; i++)
        {
            prefix[i]=abs(s[i]-t[i]);
        }

        int left=0, right=0, res=INT_MIN, sum=0;

        for(; right<n; right++)
        {
            sum+=prefix[right];

            if(sum>maxCost)
            {
                sum-=prefix[left];
                left++;
            }

            res=max(res, right-left+1);
        }

        return res;
    }
};