class Solution {
private:
    int dfs(int node, int n, vector<int>&cost, int& res)
    {
        if(node>n)
        {
            return 0;
        }

        int left=dfs(node*2, n, cost, res);
        int right=dfs(node*2+1, n, cost, res);

        res+=abs(left-right);

        return cost[node-1]+max(left, right);
    }
public:
    int minIncrements(int n, vector<int>& cost) {
        int res=0;

        dfs(1, n, cost, res);

        return res;
    }
};