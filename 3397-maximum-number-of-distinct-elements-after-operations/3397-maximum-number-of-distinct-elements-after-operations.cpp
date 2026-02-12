class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        long long last=LLONG_MIN;  
        
        int count=0;

        for(int i=0; i<n; i++)
        {
            long long low=nums[i]-k, high=nums[i]+k;

            long long candidate=max(low, last+1);

            if(candidate<=high)
            {
                count++;
                last=candidate;
            }
        }

        return count;
    }
};