class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=capacity.size();

        vector<int>diff(n, 0);

        long long sum=0;

        for(int i=0; i<n; i++)
        {
            diff[i]=capacity[i]-rocks[i];
            sum+=diff[i];
        }

        if(sum<=additionalRocks)
        {
            return n;
        }

        sort(diff.begin(), diff.end());

        int count=0;

        for(int i=0; i<n; i++)
        {
            if(diff[i]<=additionalRocks)
            {
                additionalRocks-=diff[i];
                count++;
            }
            else
            {
                break;
            }
        }

        return count;
    }
};