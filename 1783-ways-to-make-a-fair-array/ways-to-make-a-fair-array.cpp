class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();
        int odd = 0, even = 0, oddPref = 0, evenPref = 0, newOdd = 0, newEven = 0, res = 0;

        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                even+=nums[i];
            }
            else odd+=nums[i];
        }

        for(int i=0; i<n; i++)
        {   
            newOdd = evenPref + odd, newEven = oddPref + even;

            if(i%2==0)
            {   
                even-=nums[i], newEven-=nums[i], evenPref+=nums[i];
            }
            else
            {
                odd-=nums[i], newOdd-=nums[i], oddPref+=nums[i];
            }

            if(newEven==newOdd)
            {
                res++;
            }
        }

        return res;
    }
};