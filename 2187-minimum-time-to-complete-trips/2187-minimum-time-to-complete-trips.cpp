class Solution {
private:
    bool func(long long mid, vector<int>&time, int totalTrips)
    {
        long long sum=0;

        for(auto t:time)
        {
            sum+=(mid/t);

            if(sum>=totalTrips)
            {
                return true;
            }
        }

        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1, high=1LL*(*min_element(time.begin(), time.end()))*totalTrips;
        long long res=0;

        while (low<=high)
        {
            long long mid=low+(high-low)/2;

            if(func(mid, time, totalTrips))
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
