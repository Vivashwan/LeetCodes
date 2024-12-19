class Solution {
private:
    int atMost(vector<int>&nums, int k)
    {
        int res=0, left=0, oddCount=0;

        for(int right=0; right<nums.size(); right++)
        {
            if(nums[right]%2!=0)
            {
                oddCount++;
            }

            while(oddCount>k)
            {
                if(nums[left]%2!=0)
                {
                    oddCount--;
                }

                left++;
            }

            res+=right-left+1;
        }

        return res;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k)-atMost(nums, k-1);
    }
};