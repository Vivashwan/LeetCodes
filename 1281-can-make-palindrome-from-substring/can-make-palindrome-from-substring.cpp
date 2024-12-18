class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<vector<int>>prefix(n+2, vector<int>(26, 0));

        for(int i=0; i<n; i++)
        {
            prefix[i+1][s[i]-'a']++;

            for(int j=0; j<26; j++)
            {
                prefix[i+1][j]+=prefix[i][j];
            }
        }

        vector<bool>res;

        for(auto it: queries)
        {
            int left=it[0], right=it[1], k=it[2];

            if(right-left+1<=k)
            {
                res.push_back(true);
            }
            else
            {
                int odd=0;

                for(int i=0; i<26; i++)
                {
                    int count=prefix[right+1][i]-prefix[left][i];

                    if(count%2!=0)
                    {
                        odd++;
                    }
                }

                odd-=2*k;

                if(odd>1)
                {
                    res.push_back(false);
                }
                else res.push_back(true);
            }
        }
        
        return res;
    }
};