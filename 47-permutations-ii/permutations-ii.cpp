class Solution {
private:
    vector<vector<int>>res;

    void func(int ind, int n, vector<int>&nums)
    {
        if(ind==n)
        {
            res.push_back(nums);
            return;
        }

        unordered_set<int>s;

        for(int i=ind; i<n; i++)
        {
            if(s.count(nums[i]))
            {
                continue;
            }

            s.insert(nums[i]);
            
            swap(nums[ind], nums[i]);
            func(ind+1, n, nums);
            swap(nums[ind], nums[i]);
        }
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();

        func(0, n, nums);

        return res;
    }
};