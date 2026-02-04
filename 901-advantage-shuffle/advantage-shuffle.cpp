class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        map<int, int>freq;

        for(int x: nums1) 
        {
            freq[x]++;
        }
        
        int n=nums2.size();
        vector<int>ans(n);
        
        for(int i=0; i<n; i++) 
        {
            auto it=freq.upper_bound(nums2[i]);
            
            if(it==freq.end()) 
            {
                it=freq.begin();
            }
            
            ans[i]=it->first;
            
            it->second--;
            
            if(it->second==0) 
            {
                freq.erase(it);
            }
        }
        
        return ans;
    }
};
