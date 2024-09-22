class Solution {
private:
    long long formula(long long count, long long x)
    {   
        return count*x - (count*(count+1))/2;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        long long left = 1, right = maxSum;

        int res = 0;

        while(left<=right)
        {
            long long mid = left+(right-left)/2;

            long long leftCount = min((long long)index, mid-1);

            long long leftSum = formula(leftCount, mid);

            leftSum+=max((long long)0, index-(mid-1));


            long long rightCount = min((long long)n-index-1, mid-1);

            long long rightSum = formula(rightCount, mid);

            rightSum+=max((long long)0, n-index-1-(mid-1));

            long long totalSum = leftSum+mid+rightSum;

            if(totalSum<=maxSum)
            {
                res = max((long long)res, mid);

                left = mid+1;
            }
            else right = mid-1;
        }

        return res;
    }
};