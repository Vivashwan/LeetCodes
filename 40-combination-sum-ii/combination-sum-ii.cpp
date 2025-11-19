class Solution {
private:
    vector<vector<int>>res;

    void func(vector<int>&candidates, int n, int target, int sum, vector<int>temp, int ind)
    {
        if(sum==target)
        {
            res.push_back(temp);
        }

        if(sum>target)
        {
            return;
        }

        unordered_set<int>s;

        for(int i=ind; i<n; i++)
        {
            if(s.find(candidates[i])==s.end())
            {
                temp.push_back(candidates[i]);
                s.insert(candidates[i]);
                sum+=candidates[i];

                func(candidates, n, target, sum, temp, i+1);

                sum-=candidates[i];
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();

        sort(candidates.begin(), candidates.end());

        vector<int>temp;

        func(candidates, n, target, 0, temp, 0);

        return res;
    }
};