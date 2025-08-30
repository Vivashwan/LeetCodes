class Solution {
private:
    static bool myCmp(string& s1, string& s2)
    {
        return s1.length()<s2.length();
    }

    bool isPossible(string& s1, string& s2)
    {
        if(s1.length()!=s2.length()+1)
        {
            return false;
        }

        int ind1=0, ind2=0;

        while(ind1<s1.length())
        {
            if(ind2<s2.length() && s1[ind1]==s2[ind2])
            {
                ind1++, ind2++;
            }
            else if(s1[ind1]!=s2[ind2])
            {
                ind1++;
            }
        }

        if(ind1==s1.length() && ind2==s2.length())
        {
            return true;
        }
        else return false;
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n=words.size();

        int res=1;

        sort(words.begin(), words.end(), myCmp);

        vector<int>dp(n+1, 1);

        for(int ind=1; ind<n; ind++)
        {
            for(int prev=0; prev<ind; prev++)
            {
                if(isPossible(words[ind], words[prev]) && 1+dp[prev]>dp[ind])
                {
                    dp[ind]=1+dp[prev];
                }  

                res=max(res, dp[ind]);
            }
        }        

        return res;
    }
};