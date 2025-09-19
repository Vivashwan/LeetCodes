class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int res=0;

        for(int bit=0; bit<32; bit++)
        {
            int count=0;

            for(auto it: nums)
            {
                if((it>>bit)&1)
                {
                    count++;
                }
            }

            if(count>n/2)
            {
                res|=1<<bit;
            }
        }    

        return res; 
    }
};