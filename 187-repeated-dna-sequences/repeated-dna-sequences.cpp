class Solution {
private:
    bool isSafe(vector<string>&v, string str1)
    {
        for(auto it: v)
        {
            if(it==str1)
            {
                return false;
            }
        }
        
        return true;
    }

public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0;
        int n=s.length();

        vector<string>v;
        unordered_set<string>seen;

        if(n<10) 
        {
            return v;
        }

        while(i<=n-10) 
        {
            string str=s.substr(i, 10);

            if(seen.count(str)==0)
            {
                seen.insert(str);
            } 
            else 
            {
                if(v.empty() || isSafe(v, str))
                {
                    v.push_back(str);
                }
            }

            i++;
        }

        return v;
    }
};