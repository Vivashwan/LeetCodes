class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int count=0, currentEnd=0, farthestEnd=0;

        for(int i=0; i<n-1; i++)
        {
            int farthestEnd=max(farthestEnd, i+nums[i]);

            if(i==currentEnd)
            {
                count++;
                currentEnd=farthestEnd;
            }
        }

        return count;
    }
};