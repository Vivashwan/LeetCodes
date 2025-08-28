class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n=nums.size();

        int sum=0, count=0;

        unordered_set<int>s;

        s.insert(0);

        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
            if(s.count(sum-target))
            {
                count++, sum=0;
                s.clear();  s.insert(0);
            }
            else s.insert(sum);
        }

        return count;
    }
};