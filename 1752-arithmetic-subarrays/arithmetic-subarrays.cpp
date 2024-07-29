class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size(), m = l.size();

        vector<bool>res;

        for(int i=0; i<m; i++)
        {
            vector<int>temp;

            for(int j=l[i]; j<=r[i]; j++)
            {
                temp.push_back(nums[j]);
            }

            sort(temp.begin(), temp.end());

            int diff=temp[1]-temp[0];
            bool check=true;

            for(int k=2; k<temp.size(); k++)
            {
                if(temp[k]-temp[k-1]!=diff)
                {
                    check = false;
                    break;
                }
            }

            if(check==true)
            {
                res.push_back(true);
            }
            else res.push_back(false);
        }

        return res;
    }
};