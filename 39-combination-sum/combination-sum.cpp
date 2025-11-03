class Solution {
private:
    vector<vector<int>>res;

    void func(vector<int>temp, vector<int>&candidates, int ind, int target, int sum, int n)
    {
        if(ind==n)
        {
            if(sum==target)
            {
                res.push_back(temp);
            }
            return;
        }

        if(sum>target)
        {
            return;
        }

        temp.push_back(candidates[ind]);
        func(temp, candidates, ind, target, sum+candidates[ind], n);
        temp.pop_back();

        func(temp, candidates, ind+1, target, sum, n);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>temp;

        func(temp, candidates, 0, target, 0, n);

        return res;
    }
};