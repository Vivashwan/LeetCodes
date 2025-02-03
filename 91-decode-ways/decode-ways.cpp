class Solution {
private:
    int func(string &s, int n)
    {
        if(s[0]=='0') 
        {
            return 0;
        }

        int prev2=1, prev1 = 1;

        for(int i=n-1; i>=0; i--)
        {
            int curr = 0;

            if(s[i]!='0')
            {
                curr = prev1;
            
                if(i+1<n) 
                {
                    int twoDigit=stoi(s.substr(i, 2));

                    if(twoDigit>=10 && twoDigit<=26) 
                    {
                        curr+=prev2;
                    }
                }
            }

            prev2 = prev1;
            prev1 = curr;
            
        }

        return prev1;
    }
public:
    int numDecodings(string s) {
        int n = s.length();

        int count = func(s, n);

        return count;
    }
};