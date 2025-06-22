class Solution {
private:
    long long calcSum(int mid, int length)
    {
        if(mid>=length)
        {
            long long last=mid-length+1;
            return (long long)(mid+last)*length/2;
        } 
        else
        {
            long long full=(long long)(mid+1)*mid/2;
            return full+(length-mid); 
        }
    }

    bool func(int mid, int n, int index, int maxSum)
    {
        long long left=calcSum(mid-1, index);
        long long right=calcSum(mid-1, n-index-1);

        return mid+left+right<=maxSum;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        int low=1, high=maxSum;

        int res=INT_MIN;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(func(mid, n, index, maxSum))
            {
                res=mid;
                low=mid+1;
            }
            else high=mid-1;
        }

        return res;
    }
};