class Solution {
private:
    vector<vector<int>>res;
    void func(vector<int>&nums, int n, vector<int>temp, int ind)
    { 
        if(temp.size()>=2)
        {
            res.push_back(temp);
        }

        unordered_set<int>used;
        for(int i=ind; i<n; i++)
        {
            if(used.count(nums[i]))
            {
                continue;
            }

            used.insert(nums[i]);

            if(temp.empty() || nums[i]>=temp.back())
            {
                temp.push_back(nums[i]);
                func(nums, n, temp, i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n=nums.size();

        vector<int>temp;

        func(nums, n, temp, 0);

        return res;
    }
};