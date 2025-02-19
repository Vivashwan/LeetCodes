class Solution {
private:
    int t[301];
    bool solve(string s, int index, int n, unordered_set<string>&st)
    {
        if(index==n)
        {
            return true;
        }

        if(st.find(s.substr(index, n-index))!=st.end())
        {
            return true;
        }

        if(t[index]!=-1)
        {
            return t[index];
        }

        for(int len = 1; len<=n; len++)
        {
            string temp = s.substr(index, len);

            if(st.find(temp)!=st.end() and solve(s, index+len, n, st))
            {
                return true;
            }
        }

        return t[index] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();

        unordered_set<string>st;

        memset(t, -1, sizeof(t));

        for(string word: wordDict)
        {
            st.insert(word);
        }

        return solve(s, 0, n, st);
    }
};