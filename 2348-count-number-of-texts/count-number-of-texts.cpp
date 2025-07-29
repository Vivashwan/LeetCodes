class Solution {
public:
    const int MOD=1e9+7;
    string s;
    vector<int>memo;

    long long dfs(int i) 
    {
        if(i==s.size())
        {
            return 1;
        }

        if(memo[i]!=-1)
        { 
            return memo[i];
        }

        long long ways=0;
        char curr=s[i];
        int maxLen=(curr == '7' || curr=='9') ? 4 : 3;

        for(int len=1; len<=maxLen && i+len<=s.size(); len++)
        {
            if(s[i+len-1]!=curr)
            { 
                break;
            }

            ways=(ways+dfs(i+len))%MOD;
        }

        return memo[i]=ways;
    }

    int countTexts(string pressedKeys) {
        s=pressedKeys;
        memo.assign(s.size(), -1);

        return dfs(0);
    }
};
