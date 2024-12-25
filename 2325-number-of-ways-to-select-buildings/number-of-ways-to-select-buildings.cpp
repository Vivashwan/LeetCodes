class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.length();

        vector<long long> count0(n+1, 0), count1(n+1, 0);

        for(int i=0; i<n; i++)
        {
            count0[i+1] = count0[i] + (s[i] == '0' ? 1 : 0);
            count1[i+1] = count1[i] + (s[i] == '1' ? 1 : 0);
        }

        long long res = 0;

        for(int i=1; i<n-1; i++)
        {
            if(s[i]=='0')
            {
                res += count1[i]*(count1[n]-count1[i+1]);
            }
            else res += count0[i]*(count0[n]-count0[i+1]);
        }

        return res;
    }
};