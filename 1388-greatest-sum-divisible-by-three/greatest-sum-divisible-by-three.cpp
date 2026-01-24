class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int>r1, r2;

        int sum=0;

        for(auto it: nums)
        {
            sum+=it;

            if(it%3==1)
            {
                r1.push_back(it);
            }
            else if(it%3==2)
            {
                r2.push_back(it);
            }
        }

        if(sum%3==0)
        {
            return sum;
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        if(sum%3==1)
        {
            int remove1=(r1.size()>=1) ? r1[0]:INT_MAX;
            int remove2=(r2.size()>=2) ? r2[0]+r2[1]:INT_MAX;

            return sum-min(remove1, remove2);
        }

        int remove1=(r2.size()>=1) ? r2[0]:INT_MAX;
        int remove2=(r1.size()>=2) ? r1[0]+r1[1]:INT_MAX;

        return sum-min(remove1, remove2);
    }
};