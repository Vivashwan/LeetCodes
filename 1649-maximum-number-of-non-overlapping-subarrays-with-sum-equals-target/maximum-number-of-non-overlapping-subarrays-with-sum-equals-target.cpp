class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int ans=0, sum=0;

        unordered_set<int>s;

        s.insert(0);

        for(auto it: nums)
        {
            sum+=it;

            if(s.find(sum-target)!=s.end())
            {
                ans++, sum=0;

                s.clear();

                s.insert(0);
            }
            else s.insert(sum);
        }

        return ans;
    }
};