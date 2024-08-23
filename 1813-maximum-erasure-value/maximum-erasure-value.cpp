class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int sum = 0, res=0;

        unordered_set<int>st;

        int left=0, right=0;

        while(right<nums.size())
        {
            while(st.count(nums[right])>0)
            {
                st.erase(nums[left]);
                sum-=nums[left];

                left++;
            } 

            sum+=nums[right];
            st.insert(nums[right]);

            right++;

            res = max(res, sum);
        } 

        return res;
    }
};