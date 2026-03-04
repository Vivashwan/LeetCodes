class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n=beans.size();

        long long sum=0;

        for(auto it: beans)
        {
            sum+=it;
        }

        long long res=LLONG_MAX;

        sort(beans.begin(), beans.end());

        for(int i=0; i<n; i++)
        {
            long long temp=sum;

            temp-=(n-i)*beans[i];

            res=min(res, temp);
        }

        return res;
    }
};