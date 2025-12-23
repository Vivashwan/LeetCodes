class Solution {
private:
    bool canBuild(vector<int>&price, int k, int mid, int low, int high)
    {
        int n=price.size();
        int last=price[0], count=1;

        for(int i=1; i<n; i++)
        {
            if(price[i]-last>=mid)
            {
                count++;
                last=price[i];
            }

            if(count>=k)
            {
                return true;
            }
        }

        return false;
    }

public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int low=0, high=price.back()-price[0], res=0;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(canBuild(price, k, mid, low, high))
            {
                res=mid;

                low=mid+1;
            }
            else high=mid-1;
        }

        return res;
    }
};