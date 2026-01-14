class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();

        int maxVal=*max_element(nums.begin(), nums.end());

        vector<long long>freq(maxVal+n+1, 0);

        for(auto it: nums)
        {
            freq[it]++;
        }

        int count=0;

        for(int i=0; i<freq.size(); i++)
        {
            if(freq[i]>1)
            {
                int extra=freq[i]-1;

                freq[i+1]+=extra;

                count+=extra;

                freq[i]=1;
            }
        }

        return count;
    }
};