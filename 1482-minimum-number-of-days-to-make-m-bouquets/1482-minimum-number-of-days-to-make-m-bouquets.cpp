class Solution {
private:
    int func(int mid, vector<int>&bloomDay, int k, int n)
    {
        int bouquet=0, bloomedFlowers=0;

        for(int i=0; i<n; i++)
        {
            if(bloomDay[i]<=mid)
            {
                bloomedFlowers++;

                if(bloomedFlowers==k)
                {
                    bouquet++, bloomedFlowers=0;
                }
            }
            else bloomedFlowers=0;
        } 

        return bouquet;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        if(m>n/k)
        {
            return -1;
        }

        int low = 1, high = INT_MIN;

        for(int i=0; i<n; i++)
        {
            high = max(high, bloomDay[i]);
        }

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(func(mid, bloomDay, k, n)>=m)
            {
                high = mid-1;
            }
            else low = mid+1;
        }

        return low;
    }
};