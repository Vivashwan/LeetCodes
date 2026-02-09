class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        stack<int>st;
        
        for(int x: nums)
        {
            while(!st.empty() && st.top()>x) 
            {
                st.pop();
                res++;
            }

            if(x>0 && (st.empty() || st.top()<x)) 
            {
                st.push(x);
            }
        }

        res+=st.size();

        return res;
    }
};
