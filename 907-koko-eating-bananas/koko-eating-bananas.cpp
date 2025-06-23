class Solution {
private:
    bool func(vector<int>& piles, int mid, int h) {
        long long count=0; 

        for(int i=0; i<piles.size(); i++)
        {
            count += (piles[i]+mid-1)/mid;

            // Just a better replacement of this: count+=ceil(piles[i]/mid);
            // to prevent decimal trucating of cpp.
        }

        return count<=h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {

        if(piles.empty())
        { 
            return 0;
        }

        int low=1, high=*max_element(piles.begin(), piles.end());
        int res = high;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(func(piles, mid, h))
            {
                res=mid;
                high=mid-1;
            } 
            else
            {
                low=mid+1;
            }
        }

        return res;
    }
};
