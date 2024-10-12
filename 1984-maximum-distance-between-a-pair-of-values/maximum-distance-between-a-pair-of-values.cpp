class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;  
        int maxim = 0;

        while(i<n && j<m) 
        {
            if(nums1[i]<=nums2[j]) 
            {
                maxim = max(maxim, j-i);
                j++; 
            } 
            else i++;
        }

        return maxim;
    }
};