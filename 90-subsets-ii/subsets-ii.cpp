class Solution {
private:
    vector<vector<int>>res;

    void func(vector<int>&nums, int n, int ind, vector<int>temp)
    {
        res.push_back(temp);

        unordered_set<int>s;

        for(int i=ind; i<n; i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
                temp.push_back(nums[i]);
                func(nums, n, i+1, temp);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        vector<int>temp;

        func(nums, n, 0, temp);

        return res;
    }
};