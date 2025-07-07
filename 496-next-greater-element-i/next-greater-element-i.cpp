class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;

        unordered_map<int, int>mp;

        for(auto it: nums2)
        {
            while(!st.empty() && it>st.top())
            {
                mp[st.top()]=it;
                st.pop();
            }

            st.push(it);
        }

        vector<int>res(nums1.size(), -1);

        for(int i=0; i<res.size(); i++)
        {
            if(mp.count(nums1[i]))
            {
                res[i]=mp[nums1[i]];
            }
        }

        return res;
    }
};