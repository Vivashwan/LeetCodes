class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int>mp;

        for(auto it: words)
        {
            mp[it]++;
        }   

        int count=0;
        bool center=false;

        for(auto [w, f]: mp)
        {
            string rev=w;
            reverse(rev.begin(), rev.end());

            if(w==rev)
            {
                count+=(f/2)*4;

                if(f%2==1)
                {
                    center=true;
                }
            }
            else if(w<rev && mp.count(rev))
            {
                int pairs=min(f, mp[rev]);
                count+=pairs*4;
            }
        }

        if(center==true)
        {
            count+=2;
        }

        return count;
    }
};