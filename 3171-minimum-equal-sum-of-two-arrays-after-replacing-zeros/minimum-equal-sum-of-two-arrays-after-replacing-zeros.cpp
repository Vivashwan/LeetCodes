class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0, count1=0, sum2=0, count2=0;
        
        for(auto it: nums1)
        {
            if(it==0)
            {
                count1++;
                continue;
            }
            sum1+=it;
        }

        for(auto it: nums2)
        {
            if(it==0)
            {
                count2++;
                continue;
            }
            sum2+=it;
        }

        if(count1==0 && count2==0) 
        {
            return sum1==sum2 ? sum1:-1;
        } 
        else if(count1==0) 
        {
            return sum2+count2<=sum1 ? sum1:-1;
        } 
        else if(count2==0) 
        {
            return sum1+count1<=sum2 ? sum2:-1;
        }

        return max(sum1+count1, sum2+count2);
    }
};