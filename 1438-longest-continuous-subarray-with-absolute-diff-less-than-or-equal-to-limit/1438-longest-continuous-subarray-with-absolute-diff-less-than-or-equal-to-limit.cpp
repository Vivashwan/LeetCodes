class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int i =0, j;

        multiset<int>mst;

        for(j=0; j<nums.size(); j++)
        {
            mst.insert(nums[j]);

            if(*mst.rbegin()-*mst.begin()>limit)
            {
                mst.erase(mst.find(nums[i]));
                i++;
            }
        }

        return j-i;
    }
};