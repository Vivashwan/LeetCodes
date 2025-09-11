class Solution {
private:
    void func(int stone, unordered_map<int, vector<int>>&rowStones, unordered_map<int, vector<int>>&colStones, vector<vector<int>>&stones, vector<bool>&visited)
    {
        visited[stone]=true;

        int row=stones[stone][0], col=stones[stone][1];

        for(auto it: rowStones[row])
        {
            if(!visited[it])
            {
                func(it, rowStones, colStones, stones, visited);
            }
        }

        for(auto it: colStones[col])
        {
            if(!visited[it])
            {
                func(it, rowStones, colStones, stones, visited);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();

        unordered_map<int, vector<int>>rowStones, colStones;
        
        vector<bool>visited(n, false);

        for(int i=0; i<stones.size(); i++)
        {
            int row=stones[i][0], col=stones[i][1];

            rowStones[row].push_back(i);
            colStones[col].push_back(i);
        }

        int connectedComponents=0;

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                func(i, rowStones, colStones, stones, visited);
                connectedComponents++;
            }
        }

        return n-connectedComponents;
    }
};