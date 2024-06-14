class Solution {
private:
    int func(vector<int>&temp)
    {
        int res=0, len=0;

        for(auto it: temp)
        {
            len=it==0?0:len+1;
            res+=len;
        }

        return res;
    }
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int ans=0;

        for(int i=0; i<n; i++)
        {
            vector<int>temp(m, 1);

            for(int j=i; j<n; j++)
            {
                for(int k=0; k<m; k++)
                {
                    temp[k]&=mat[j][k];
                }
                
                ans+=func(temp);
            }

        }

        return ans;
    }
};