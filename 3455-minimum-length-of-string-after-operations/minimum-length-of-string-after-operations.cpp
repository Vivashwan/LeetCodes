class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        
        unordered_map<int, int>mp;
        
        for(auto it: s)
        {
            mp[it]++;
        }
        
        int res = 0;
        
        for(auto it : mp)
        {
            int val = it.second;
            res += (val%2) ? val - 1 : val - 2;
        }
        
        return n - res;
    }
};