class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        multiset<int>ms(begin(nums1), end(nums1));

        for(int i=0; i<n; i++)
        {
            auto it=ms.upper_bound(nums2[i]);

            if(it==end(ms))
            {
                it=begin(ms);
            }

            nums1[i]=*it;

            ms.erase(it);
        }

        return nums1;
    }
};