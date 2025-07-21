class Solution {
public:
    void recursive(vector<vector<int>>&res, int target, int curr, int ind, vector<int>&temp, vector<int>&candidates)
    {
        if(curr>target || ind==candidates.size())
        { 
            return;
        }

        if(curr==target)
        {
            res.push_back(temp);
            return;
        }

        recursive(res, target, curr, ind+1, temp, candidates);

        temp.push_back(candidates[ind]);

        recursive(res, target, curr+candidates[ind], ind, temp, candidates);

        temp.pop_back();
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;

        recursive(res, target, 0, 0, temp, candidates);

        return res;
    }
};
