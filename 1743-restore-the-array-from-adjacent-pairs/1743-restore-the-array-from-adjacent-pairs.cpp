class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size()+1;

        unordered_map<int, vector<int>>graph;
        
        for(auto it: adjacentPairs)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        int start;

        for(auto it: graph)
        {
            if(it.second.size()==1)
            {
                start = it.first;
                break;
            }
        }

        int curr = start, prev = INT_MIN;

        vector<int>res;

        while(res.size()<n)
        {
            res.push_back(curr);

            for(auto it: graph[curr])
            {
                if(it!=prev)
                {
                    prev = curr;
                    curr = it;
                    break;
                }
            }
        }

        return res; 
    }
};