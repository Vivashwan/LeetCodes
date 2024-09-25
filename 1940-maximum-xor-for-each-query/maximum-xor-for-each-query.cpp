class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();

        vector<int>res(n);

        int maxXor = pow(2, maximumBit)-1;

        vector<int>prefixXor(n+1);

        prefixXor[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            prefixXor[i] = prefixXor[i-1]^nums[i];
        }

        for(int i=0; i<n; i++)
        {
            res[i] = maxXor ^ prefixXor[n-i-1];
        }

        return res;   
    }
};