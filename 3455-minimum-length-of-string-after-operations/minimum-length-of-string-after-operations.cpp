class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        
        unordered_map<int, int>mp;
        
        for(auto it: s)
        {
            mp[it]++;
        }
        
        int count = 0;
        
        for(auto it: mp)
        {
            int v = it.second;
            if(v%2==0)
            {
                count+=2;
            }
            else 
            {
                count+=1;
            }
        }
        
        return count;
    }
};