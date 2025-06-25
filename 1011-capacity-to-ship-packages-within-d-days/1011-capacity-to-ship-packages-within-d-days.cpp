class Solution {
private:
    bool func(int mid, vector<int>&weights, int days)
    {
        int count=1, currWeight=0;

        for(int i=0; i<weights.size(); i++)
        {
            if(currWeight+weights[i]<=mid)
            {
                currWeight+=weights[i];
            }
            else count++, currWeight=weights[i];
        }

        return count<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(), weights.end());
        int high=accumulate(weights.begin(), weights.end(), 0);

        int res=high;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(func(mid, weights, days))
            {
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }

        return res;
    }
};