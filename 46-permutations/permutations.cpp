class Solution {
private:
    void permutationCalculator(vector<int>& nums, vector<vector<int>>& ans, int ind, int n)
    {
        if(ind==n-1)
        {
            ans.push_back(nums);
            return;
        }

        for(int i=ind; i<n; i++)
        {
            swap(nums[i], nums[ind]);

            permutationCalculator(nums, ans, ind+1, n);

            swap(nums[ind], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        int n=nums.size();

        permutationCalculator(nums, ans, 0, n);

        return ans;
    }
};