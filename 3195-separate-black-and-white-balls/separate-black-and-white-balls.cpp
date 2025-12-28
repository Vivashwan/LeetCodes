class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.length();

        long long count=0, res=0;

        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='0')
            {
                count++;
            }

            if(s[i]=='1')
            {
                res+=count;
            }
        }

        return res;
    }
};