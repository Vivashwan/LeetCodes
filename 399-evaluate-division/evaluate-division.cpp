class Solution {
private:
    double func(string start, string end, unordered_map<string, vector<pair<string, double>>>&mp, unordered_set<string>&visited)
    {
        if(mp.find(start)==mp.end())
        {
            return -1.0;
        }

        if(start==end)
        {
            return 1.0;
        }

        visited.insert(start);

        for(auto it: mp[start])
        { 
            auto [nextPos, val]=it;

            if(visited.count(nextPos))
            { 
                continue;
            }

            double result=func(nextPos, end, mp, visited);

            if(result!=-1.0)
            {
                return result*val;
            }
        }

        return -1.0;
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>>mp;

        for(int i=0; i<equations.size(); i++)
        {
            mp[equations[i][0]].push_back({equations[i][1], values[i]});
            mp[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }

        vector<double>res;

        for(auto it: queries)
        {
            string start=it[0], end=it[1];

            unordered_set<string>visited;

            double result=func(start, end, mp, visited);

            res.push_back(result);
        }

        return res;
    }
};