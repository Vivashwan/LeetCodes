class Solution {
private:
    bool canMakeBouquets(int day, vector<int>&bloomDay, int m, int k)
    {
        int bouquets=0, flowers=0;

        for(int bloom: bloomDay)
        {
            if(bloom<=day)
            {
                flowers++;
                if(flowers==k) 
                {
                    bouquets++;
                    flowers=0;
                }
            }
            else flowers=0;
        }

        return bouquets>=m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long totalFlowers=(long long)m*k;

        if(bloomDay.size()<totalFlowers)
        { 
            return -1;
        }

        int low=*min_element(bloomDay.begin(), bloomDay.end());
        int high=*max_element(bloomDay.begin(), bloomDay.end());

        int res=-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(canMakeBouquets(mid, bloomDay, m, k))
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