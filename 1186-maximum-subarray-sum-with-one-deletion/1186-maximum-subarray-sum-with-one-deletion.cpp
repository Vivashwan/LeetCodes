class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();

        vector<int>forward(n), backward(n);

        int ans = INT_MIN;

        int sum=0;

        for(int i=0; i<n; i++)
        {
            sum+=arr[i];

            forward[i]=sum;

            ans = max(ans, sum);

            if(sum<0)
            {
                sum=0;
            }
        }

        sum=0; 

        for(int i=n-1; i>=0; i--)
        {
            sum+=arr[i];

            backward[i]=sum;

            ans = max(ans, sum);

            if(sum<0)
            {
                sum=0;
            }
        }
        
        for(int i=1; i<n-1; i++)
        {
            ans = max(ans, forward[i-1]+backward[i+1]);
        }

        return ans;
    }
};