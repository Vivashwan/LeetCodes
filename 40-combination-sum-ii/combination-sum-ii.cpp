class Solution {
public:
    void func(vector<vector<int>>&ans, int target, int sum, int ind, vector<int>&temp, vector<int>&candidates, vector<bool>&visited)
    {
        if(sum>target)
        {
            return;
        }

        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }

        for(int i=ind; i<candidates.size(); i++) 
        {
            if(i>ind && candidates[i]==candidates[i-1])
            {
                continue;
            }

            if(!visited[i])
            {
                sum+=candidates[i];
                temp.push_back(candidates[i]);
                visited[i]=true;

                func(ans, target, sum, i+1, temp, candidates, visited);
                
                temp.pop_back();
                visited[i]=false;
                sum-=candidates[i];
            }
    }
}

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;

        vector<int>temp;
        vector<bool>visited(candidates.size(), false);

        sort(candidates.begin(), candidates.end());

        func(ans, target, 0, 0, temp, candidates, visited);

        return ans;
    }
};