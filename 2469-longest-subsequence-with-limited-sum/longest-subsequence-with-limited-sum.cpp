class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> prefixSum(n);
        int sum = 0;
        for(int i = 0; i<n; i++)
        {
            sum += nums[i];
            prefixSum[i] = sum;
        }
        
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i<m ; i++)
        {
            int lo = 0, hi = n-1;
            while(lo<=hi){
                int mid = lo + (hi-lo)/2;
                if(prefixSum[mid]<=queries[i]){
                    ans[i] = mid + 1;
                    lo = mid + 1;
                }
                else hi = mid - 1;
            }
        }
        return ans;
    }
};