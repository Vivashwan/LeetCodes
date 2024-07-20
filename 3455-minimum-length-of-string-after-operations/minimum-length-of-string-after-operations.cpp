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
        
        for(auto x : mp){
            int f = x.second;
            res += (f%2) ? f - 1 : f - 2;
        }
        return n - res;
    }
};