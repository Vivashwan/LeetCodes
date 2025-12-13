class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n=nums.size();

        sort(nums.begin(), nums.end());

        int left=0, right=2;

        vector<vector<int>>res;

        for(; right<n; right+=3)
        {
            if(nums[right]-nums[left]>k)
            {
                return {};
            }

            vector<int>temp;

            for(int j=left; j<=right; j++)
            {
                temp.push_back(nums[j]);
            }

            res.push_back(temp);
            left+=3;
        }

        return res;
    }
};