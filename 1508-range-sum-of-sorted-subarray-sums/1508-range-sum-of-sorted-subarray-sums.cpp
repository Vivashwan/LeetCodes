#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MOD=1e9+7;

public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>prefix(n+1, 0);

        for(int i=0; i<n; i++)
        {    
            prefix[i+1]=prefix[i]+nums[i];
        }

        vector<int>subSums;
        
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                subSums.push_back(prefix[j]-prefix[i]);
            }
        }

        sort(subSums.begin(), subSums.end());

        long long res=0;

        for(int i=left-1; i<=right-1; i++)
        {
            res=(res+subSums[i])%MOD;
        }

        return (int)res;
    }
};
