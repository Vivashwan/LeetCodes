class Solution {
private:
    int atMost(vector<int>&nums, int n, int k)
    {
        int left=0, count=0, odd=0;

        for(int right=0; right<n; right++)
        {
            if(nums[right]%2!=0)
            {
                odd++;
            }

            while(odd>k)
            {
                if(nums[left]%2!=0)
                {
                    odd--;
                }  

                left++; 
            }

            count+=right-left+1;
        }

        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();

        return atMost(nums, n, k)-atMost(nums, n, k-1);
    }
};