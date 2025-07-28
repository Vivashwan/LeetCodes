class Solution {
private:
    void func(int ind, vector<int>&nums, int n, vector<vector<int>>&res)
    {
        if(ind==n-1)
        {
            res.push_back(nums);
            return;
        }

        unordered_set<int>st;

        for(int i=ind; i<n; i++)
        {
            if(st.count(nums[i]))
            {
                continue;
            }

            st.insert(nums[i]);

            swap(nums[ind], nums[i]);
            func(ind+1, nums, n, res);
            swap(nums[i], nums[ind]);

        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;

        int n=nums.size();

        func(0, nums, n, res);

        return res;
    }
};