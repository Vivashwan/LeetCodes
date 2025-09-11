class Solution {
private:
    void func(int person, unordered_map<int, vector<int>>&mp, vector<int>&quiet, vector<int>&res) 
    {
        if(res[person]!=-1)
        { 
            return;
        }

        res[person]=person;

        for(int richerPerson: mp[person]) 
        {
            func(richerPerson, mp, quiet, res);

            if(quiet[res[richerPerson]]<quiet[res[person]]) 
            {
                res[person]=res[richerPerson];
            }
        }
    }

public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int m=quiet.size();
        
        unordered_map<int, vector<int>> mp;

        for(auto& r: richer) 
        {
            mp[r[1]].push_back(r[0]);
        }

        vector<int>res(m, -1);

        for(int j=0; j<m; j++) 
        {
            func(j, mp, quiet, res);
        }

        return res;
    }
};
