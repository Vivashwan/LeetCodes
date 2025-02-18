class Solution {
private:
    bool func(vector<int>&nums, int n, int k, int ind, int currSum, vector<bool>&visited, int target)
    {
        if(k==1)
        {
            return true;
        }

        if(ind>=n)
        {
            return false;
        }

        if(target==currSum)
        {
            return func(nums, n, k-1, 0, 0, visited, target);
        }

        for(int i=ind; i<n; i++)
        {
            if(visited[i] || currSum+nums[i]>target)
            {
                continue;
            }
            
            if(!visited[i])
            {
                visited[i]=true;

                if(func(nums, n, k, i+1, currSum+nums[i], visited, target))
                {
                    return true;
                }

                visited[i]=false;
            }
        }

        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();

        int total=accumulate(nums.begin(), nums.end(), 0);

        if(total%k)
        {
            return false;
        }

        vector<bool>visited(n, false);

        return func(nums, n, k, 0, 0, visited, total/k);
    }
};