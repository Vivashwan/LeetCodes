class Solution {
public:
    int numTimesAllBlue(vector<int>& arr) {
        int sum=0, indSum=0, count=0, n=arr.size();

        for(int i=0; i<n; i++)
        {
            sum+=arr[i]-1;
            indSum+=i;

            if(sum==indSum)
            {
                count++;
            }
        }

        return count;
    }
};