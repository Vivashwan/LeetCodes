class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long n = beans.size();

        sort(beans.begin(), beans.end());

        long long sum = 0;

        for(auto it: beans)
        {
            sum+=it;
        }

        long long mini = LLONG_MAX;

        for(int i=0; i<n; i++)
        {
            long long temp = sum;

            temp -= (n-i)*beans[i];

            mini = min(mini, temp);
        }

        return mini;
    }
};