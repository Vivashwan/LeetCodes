class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int>prefixSum(2051, 0);

        int res=0;

        for(auto it: logs)
        {
            prefixSum[it[0]]++;
            prefixSum[it[1]]--;
        }

        for(int i=1950; i<=2050; i++)
        {
            prefixSum[i]+=prefixSum[i-1];

            if(prefixSum[i]>prefixSum[res])
            {
                res=i;
            }
        }

        return res;
    }
};