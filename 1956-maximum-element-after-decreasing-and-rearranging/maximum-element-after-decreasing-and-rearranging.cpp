class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        int n = arr.size();

        arr[0] = 1;

        int maxim = arr[0];

        for(int i=1; i<n; i++)
        {
            if(abs(arr[i]-arr[i-1])>1)
            {
                arr[i] = arr[i-1]+1;
                maxim = max(maxim, arr[i]);
            }
            else
            {
                maxim = max(maxim, arr[i]);
            }
        }

        return maxim;
    }
};