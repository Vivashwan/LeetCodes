class Solution {
private:
    int MOD = 1e9+7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0, count = 0, even = 0, odd = 0;

        for(int i=0; i<n; i++)
        {
            sum+=arr[i];

            if(sum%2!=0)
            {
                odd++, count++;
                count = (count+even)%MOD;
            }
            else
            {
                even++;
                count = (count+odd)%MOD;
            }
        }

        return count%MOD;
    }
};