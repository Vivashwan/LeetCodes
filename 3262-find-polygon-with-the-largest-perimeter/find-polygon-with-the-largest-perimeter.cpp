class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();

        long long total=0;

        for(int x: nums)
        { 
            total+=x;
        }

        sort(nums.begin(), nums.end());

        for(int i=n-1; i>=2; i--)
        {
            long long largest=nums[i];
            long long rest=total-largest;

            if(rest>largest)
            {
                return rest+largest;
            }

            total-=largest;
        }

        return -1;
    }
};