class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n=s.size();

        vector<int>prefix(n, 0), candles, res;

        int count=0;

        for(int i=0; i<n; i++)
        {
            if(s[i]=='*')
            {
                count++;
            }

            if(s[i]=='|')
            {
                candles.push_back(i);
            }

            prefix[i]=count;
        }

        for(auto it: queries)
        {
            int left=it[0], right=it[1];

            int leftBoundary=lower_bound(candles.begin(), candles.end(), left)-candles.begin();

            int rightBoundary=upper_bound(candles.begin(), candles.end(), right)-candles.begin();

            if(leftBoundary<candles.size() && rightBoundary>=0 && leftBoundary<rightBoundary)
            {
                res.push_back(prefix[candles[rightBoundary-1]]-prefix[candles[leftBoundary]]);
            }
            else 
            {
                res.push_back(0); 
            }
        }

        return res;
    }
};