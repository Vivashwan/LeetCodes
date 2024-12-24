class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        vector<int>left(n, 0), right(n, 0), res;

        for(int i=1; i<n; i++)
        {
            if(security[i]<=security[i-1])
            {
                left[i]=1+left[i-1];
            }
        }

        for(int i=n-2; i>=0; i--)
        {
            if(security[i]<=security[i+1])
            {
                right[i]=1+right[i+1];
            }
        }

        for(int i=time; i<n-time; i++)
        {
            if(left[i]>=time && right[i]>=time)
            {
                res.push_back(i);
            }
        }

        return res;
    }
};