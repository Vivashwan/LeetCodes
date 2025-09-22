class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();

        if(n<10)
        {
            return {};
        }

        unordered_map<char, int>mp={{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

        unordered_set<int>seen, repeated;
        vector<string>res;

        int mask=0;

        for(int i=0; i<n; i++)
        {
            mask=((mask<<2) | mp[s[i]]) & ((1<<20)-1);

            if(i>=9) 
            {
                if(seen.count(mask))
                {
                    if(!repeated.count(mask))
                    {
                        res.push_back(s.substr(i-9, 10));
                        repeated.insert(mask);
                    }
                }
                else
                {
                    seen.insert(mask);
                }
            }
        }

        return res;
    }
};