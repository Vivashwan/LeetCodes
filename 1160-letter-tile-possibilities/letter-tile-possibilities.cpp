class Solution {
private:
    int dfs(unordered_map<char, int>&mp)
    {
        int total=0;

        for(auto& [ch, count]: mp)
        {
            if(count==0)
            {
                continue;
            }

            total++;

            mp[ch]--;

            total+=dfs(mp);

            mp[ch]++;
        }

        return total;
    }
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int>mp;

        for(auto it: tiles)
        {
            mp[it]++;
        }

        return dfs(mp);
    }
};