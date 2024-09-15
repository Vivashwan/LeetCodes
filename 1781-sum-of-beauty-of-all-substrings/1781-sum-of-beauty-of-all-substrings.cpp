class Solution {
public:
    int beautySum(string s) {
        int res=0, n=s.length();

        for(int i=0; i<n; i++)
        {
            unordered_map<char, int>mp;

            for(int j=i; j<n; j++)
            {
                mp[s[j]]++;

                int mini=INT_MAX, maxi=INT_MIN;

                for(auto it: mp)
                {
                    mini = min(mini, it.second);
                    maxi = max(maxi, it.second);
                }

                res+=maxi-mini; 
            }
        }

        return res;
    }
};