class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;

        for(auto c: s) 
        {
            mp[c]++;
        }

        string str="";

        for(auto &c: order) 
        {
            if(mp.find(c)!=mp.end())
            {
                str.append(mp[c], c);
                mp.erase(c);
            }
        }

        for(auto &p: mp) 
        {
            str.append(p.second, p.first);
        }

        return str;
    }
};
