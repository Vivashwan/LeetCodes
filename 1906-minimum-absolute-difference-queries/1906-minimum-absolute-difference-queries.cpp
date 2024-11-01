class Solution {
public:
    vector<int> mp[101];
    int solve(vector<int> &a,int l,int r)
    {
        int s = 0, e = a.size() - 1;
        
        while(s<=e)
        {
            int mid = (s + e)/2;

            if(a[mid]>=l and a[mid]<=r)
            {
                return 1;
            }
            else if(a[mid]>r)
            {
                e = mid - 1;
            }
            else s = mid + 1;
        }

        return 0;
    }
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
        
        for(auto it:queries)
        {
            int l = it[0], r = it[1];

            vector<int> st;

            for(int i=0; i<101; i++)
            {
                if(solve(mp[i],l,r))
                {    
                    st.push_back(i);
                }
            }
            
            if(st.size()==1)
            {
                ans.push_back(-1);
            }
            else
            {
                sort(st.begin(),st.end());      
                int mn = INT_MAX;
                
                for(int k=1; k<st.size(); k++)
                {
                    mn = min(mn, st[k]-st[k-1]);
                }
                
                ans.push_back(mn);
            }
        }
        return ans;
    }
};