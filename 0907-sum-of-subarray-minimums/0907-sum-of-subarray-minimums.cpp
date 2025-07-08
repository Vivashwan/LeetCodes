class Solution {
private:
    const int MOD=1e9+7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();

        stack<pair<int, int>>st1, st2;

        vector<int>left(n, -1), right(n, -1);

        for(int i=0; i<n; i++)
        {
            int count=1;

            while(!st1.empty() && st1.top().first>arr[i])
            {
                count+=st1.top().second;
                st1.pop();
            }
            st1.push({arr[i], count});

            left[i]=count;
        }

        for(int i=n-1; i>=0; i--)
        {
            int count=1;

            while(!st2.empty() && st2.top().first>=arr[i])
            {
                count+=st2.top().second;
                st2.pop();
            }

            st2.push({arr[i], count});
            right[i]=count;
        }

        int res=0;

        for(int i=0; i<n; i++)
        {
            res=(res+(long long)arr[i]*left[i]*right[i])%MOD;
        }

        return (int)res;
    }
};