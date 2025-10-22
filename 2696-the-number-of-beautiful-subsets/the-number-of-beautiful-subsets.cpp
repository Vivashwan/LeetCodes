class Solution {
private:
    int count=0;

    void dfs(int ind, vector<int>&nums, vector<int>&freq, int k)
    {
        if(ind==nums.size())
        {
            if(accumulate(freq.begin(), freq.end(), 0)>0)
            { 
                count++;
            }

            return;
        }

        dfs(ind+1, nums, freq, k);

        int val=nums[ind];

        if((val-k<0 || !freq[val-k]) && (val+k>=2000 || !freq[val+k]))
        {
            freq[val]++;

            dfs(ind+1, nums, freq, k);

            freq[val]--;
        }
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<int>freq(2001, 0);

        dfs(0, nums, freq, k);

        return count;
    }
};