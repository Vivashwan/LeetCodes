class Solution {
private:
    int closest(int a, int b, int target)
    {   
        if(a==0)
        {
            return b;
        }
        if(b==0)
        {
            return a;
        }
        if(abs(target-a)==abs(target-b))
        {
            return a<b?a:b;
        }    
        return abs(target-a)<abs(target-b)?a:b; 
    }
    
    int dfs(vector<int>&toppingCosts, int sum, int ind, int target)
    {
        if(ind>=toppingCosts.size())
        {
            return sum;
        }

        int val1 = dfs(toppingCosts, sum+toppingCosts[ind], ind+1, target);

        int val2 = dfs(toppingCosts, sum+(toppingCosts[ind]*2), ind+1, target);

        int val3 = dfs(toppingCosts, sum, ind+1, target);

        sum = closest(val1, closest(val2, val3, target), target);

        return sum;
    }

public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = 0;

        for(int i=0; i<baseCosts.size(); i++)
        {
            res = closest(dfs(toppingCosts, baseCosts[i], 0, target), res, target);
        }   

        return res; 
    }
};