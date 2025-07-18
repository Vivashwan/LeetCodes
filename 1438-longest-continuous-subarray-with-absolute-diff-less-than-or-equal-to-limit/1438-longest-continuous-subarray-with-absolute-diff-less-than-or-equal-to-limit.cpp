class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();

        deque<int>maxDeque, minDeque;

        int left=0, res=0;

        for(int right=0; right<n; right++)
        {
            while(!maxDeque.empty() && nums[right]>nums[maxDeque.back()])
            {
                maxDeque.pop_back();
            }

            maxDeque.push_back(right);

            while(!minDeque.empty() && nums[right]<nums[minDeque.back()])
            {
                minDeque.pop_back();
            }

            minDeque.push_back(right);

            while(nums[maxDeque.front()]-nums[minDeque.front()]>limit)
            {
                left++;

                if(maxDeque.front()<left)
                {
                    maxDeque.pop_front();
                }

                if(minDeque.front()<left)
                {
                    minDeque.pop_front();
                }
            }

            res=max(res, right-left+1);
        }

        return res;
    }
};