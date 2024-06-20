class Solution {
private:
    int MOD = 1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        long long res = 0, countOdd = 0, countEven = 0, currSum = 0;

        for(int i=0; i<n; i++)
        {
            currSum+=arr[i];

            if(currSum%2==0)
            {
                res+=countOdd;

                countEven++;
            }
            else
            {
                res+=countEven+1;

                countOdd++;
            }

            res%=MOD;
        }

        return res;
    }
};