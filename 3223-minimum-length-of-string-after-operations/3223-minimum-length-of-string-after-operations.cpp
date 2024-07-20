class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        
        // if(n<=2)
        // {
        //     return 2;
        // }
        
        unordered_map<int, int>mp;
        
        for(auto it: s)
        {
            mp[it]++;
        }
        
        int count = 0;
        
        for(auto it: mp)
        {
            auto v = it.second;
            if(v%2==0)
            {
                count+=2;
            }
            else if(v%3==0)
            {
                count+=1;
            }
        }
        
        return count;
    }
};