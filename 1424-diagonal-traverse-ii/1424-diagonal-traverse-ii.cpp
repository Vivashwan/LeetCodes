class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n = nums.size();

        int m = 0;

        for(int i=0; i<n; i++)
        {
            if(nums[i].size()>m)
            {
                m = nums[i].size();
            }
        }

        vector<vector<int>>temp(n+m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<nums[i].size(); j++)
            {
                temp[i+j].push_back(nums[i][j]);
            }
        }

        for(int i=0;i<m+n;i++)
        {
            reverse(temp[i].begin(),temp[i].end());
        }

        vector<int>res;

        for(int i=0; i<n+m; i++)
        {
            for(int j=0; j<temp[i].size(); j++)
            {
                res.push_back(temp[i][j]);
            }
        }

        return res;
    }
};