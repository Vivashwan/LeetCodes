class Solution {
private:
    int countHistograms(vector<int>&nums, int n)
    {
        stack<int>st;

        vector<int>count(n, 0);

        int res=0;

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }

            if(st.empty())
            {
                count[i]=nums[i]*(i+1);
            }
            else
            {
                int prev=st.top();
                count[i]=count[prev]+nums[i]*(i-prev);
            }

            st.push(i);
            res+=count[i];
        }

        return res;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();

        vector<vector<int>>temp=mat;

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(temp[i][j]==1)
                {
                    temp[i][j]=temp[i][j]+temp[i-1][j];
                }
            }
        }

        int total=0;

        for(int i=0; i<n; i++)
        {
            total+=countHistograms(temp[i], m);
        }

        return total;
    }
};