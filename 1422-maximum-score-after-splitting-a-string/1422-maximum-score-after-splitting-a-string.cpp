class Solution {
public:
    int maxScore(string s) {
        int n = s.length();

        vector<int>leftZeroes(n, 0), rightOnes(n, 0);

        int count=0;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='0')
            {
                count++;
            }
            leftZeroes[i] = count;
        }

        count=0;

        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='1')
            {
                count++;
            }
            rightOnes[i] = count;
        }

        int start = leftZeroes[0] == 0 ? 1: 0,
        end = rightOnes[n-1] == 0 ? n-2: n-1;

        int res = 0;

        for(; start<=end; start++)
        {
            res = max(res, leftZeroes[start]+rightOnes[start]);
        }

        return res;
    }
};