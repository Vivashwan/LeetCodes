class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>st;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[i]<st.back() && (st.size()-1+n-i)>=k)
            {
                st.pop_back();
            }

            if(st.size()<k)
            {
                st.push_back(nums[i]);
            }
        }

        return st;
    }
};