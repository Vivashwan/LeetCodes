class Solution {
private:
    int func(int mid, vector<int>&arr)
    {
        int sum=0;

        for(auto it: arr)
        {
            sum+=min(mid, it);
        }

        return sum;
    }

public:
    int findBestValue(vector<int>& arr, int target) {
        int n=arr.size();

        int low=0, high=*max_element(arr.begin(), arr.end());

        int res=INT_MAX, minDiff=INT_MAX;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            int closestSum=func(mid, arr);

            int diff=abs(target-closestSum);

            if(diff<minDiff || (diff == minDiff && mid<res))
            {
                minDiff=diff;
                res=mid;
            }

            if(closestSum<target)
            {
                low=mid+1;
            }
            else high=mid-1;
        }

        return res;
    }
};