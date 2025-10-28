class Solution {
private:
    int count=0;
    
    void func(unordered_map<char, int>&mp)
    {
        for(auto it: mp)
        {
            if(it.second==0) 
            {
                continue;
            }

            mp[it.first]--;

            count++;

            func(mp);

            mp[it.first]++;
        }
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int>mp;

        for(auto it: tiles)
        {
            mp[it]++;
        }

        func(mp);

        return count;
    }
};