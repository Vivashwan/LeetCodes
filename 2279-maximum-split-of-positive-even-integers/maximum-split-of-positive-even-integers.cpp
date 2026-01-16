class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0)
        { 
            return {};
        }

        vector<long long>res;
        long long curr=2, sum=0;

        while(sum+curr<=finalSum) 
        {
            res.push_back(curr);
            sum+=curr;
            curr+=2;
        }

        long long leftover=finalSum-sum;

        if(leftover>0) 
        {
            res.back()+=leftover;
        }

        return res;
    }
};