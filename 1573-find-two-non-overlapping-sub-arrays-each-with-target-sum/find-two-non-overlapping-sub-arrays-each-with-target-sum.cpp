class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        unordered_map<int, int>mp;

        mp[0]=-1;

        vector<int>minLen(n, INT_MAX);

        int res=INT_MAX, sum=0, minSoFar=INT_MAX;

        for(int i=0; i<n; i++)
        {
            sum+=arr[i];

            if(mp.find(sum-target)!=mp.end())
            {
                int startInd=mp[sum-target];
                int currLen=i-startInd;

                if(startInd>=0 && minLen[startInd]!=INT_MAX)
                {
                    res=min(res, minLen[startInd]+currLen);
                }

                minSoFar=min(minSoFar, currLen);
            }

            minLen[i]=minSoFar;
            mp[sum]=i;
        }

        return res==INT_MAX?-1:res;
    }
};