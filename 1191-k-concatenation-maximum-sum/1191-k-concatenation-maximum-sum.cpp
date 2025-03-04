class Solution {
private:
    int MOD=1e9+7;

    int kadaneForOne(vector<int>&arr, int n)
    {
        int res=arr[0], curr=arr[0];

        for(int i=1; i<n; i++)
        {
            curr=max(arr[i], curr+arr[i]);
            res=max(res, curr);
        }

        return res;
    }

    int kadaneForTwo(vector<int>&arr, int n)
    {
        int res=arr[0], curr=arr[0];

        for(int i=1; i<2*n; i++)
        {
            curr=max(arr[i%n], curr+arr[i%n]);
            res=max(res, curr);
        }

        return res;
    }
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n = arr.size();

        long long sum = accumulate(arr.begin(), arr.end(), 0);

        int res=0;

        if(k==1)
        {
            res=(kadaneForOne(arr, n))%MOD;
        }
        else if(sum>0)
        {
            res=(kadaneForTwo(arr,n) + ((k-2) * (sum)))%MOD;
        }
        else res=(kadaneForTwo(arr, n))%MOD;
        
        if(res<0)
        {
            return 0;
        }

        return res%MOD;
    }
};