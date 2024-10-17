class Solution {
private:
    bool check(int mid, vector<int>&dist, double hour, int n)
    {
        double ans = 0;

        for(int i=0; i<n-1; i++)
        {
           ans += ceil((double)dist[i]/mid);
        }

        ans+=(double)dist[n-1]/mid;

        return ans<=hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int res = -1, n = dist.size(), low = 1, high = 1e7;

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(check(mid, dist, hour, n))
            {
                res = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return res;
    }
};