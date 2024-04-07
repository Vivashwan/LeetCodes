class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        long long count=0, sum=0;

        for(int i=0; i<k; i++)
        {
            sum+=arr[i];
        }

        int avg = sum/k;

        if(avg>=threshold)
        {
            count++;
        }

        for(int j=k; j<n; j++)
        {
            sum-=arr[j-k];
            sum+=arr[j];

            avg = sum/k;

            if(avg>=threshold)
            {
                count++;
            }
        }

        return count;
    }
};