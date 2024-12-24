class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size(), count = 0;

        vector<int>prefix(n, 0), candles, res;

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
            int l = lower_bound(candles.begin(), candles.end(), it[0])-candles.begin();
            int r = upper_bound(candles.begin(), candles.end(), it[1])-candles.begin();

            if(l < candles.size() && r > 0 && l < r) 
            {    
                res.push_back(prefix[candles[r-1]] - prefix[candles[l]]);
            } 
            else 
            {
                res.push_back(0); 
            }
        }

        return res;
    }
};