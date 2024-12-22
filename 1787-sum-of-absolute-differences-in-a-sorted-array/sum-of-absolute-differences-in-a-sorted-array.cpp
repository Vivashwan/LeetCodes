class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        int leftSum = 0, rightSum = 0;
        for(int x:nums) rightSum += x;

        for(int i=0; i<n; i++){
            int absDiff = ((i*nums[i]) - leftSum) + (rightSum - (n-1-i+1)*nums[i]);
            ans.push_back(absDiff);
            leftSum += nums[i];
            rightSum -= nums[i];
        }

        return ans;
    }
};