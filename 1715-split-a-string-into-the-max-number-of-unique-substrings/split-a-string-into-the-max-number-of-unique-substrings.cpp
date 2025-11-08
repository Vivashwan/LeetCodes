class Solution {
public:
    void dfs(string &s, int start, unordered_set<string>&used, int count, int &best) 
    {
        if(start==s.size()) 
        {
            best=max(best, count);
            return;
        }

        for(int end=start; end<s.size(); ++end) 
        {
            string sub=s.substr(start, end-start+1);

            if(used.find(sub)==used.end()) 
            {
                used.insert(sub);
                dfs(s, end+1, used, count+1, best);
                used.erase(sub);
            }
        }
    }

    int maxUniqueSplit(string s) {
        int best=0;
        unordered_set<string>used;
        dfs(s, 0, used, 0, best);
        return best;
    }
};