class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();

        vector<double>times(n);

        for(int i=0; i<n; i++)
        {
            times[i] = (double)dist[i]/(double)speed[i];
        }

        sort(times.begin(), times.end());

        for(int i=0; i<n; i++)
        {
            if(i>=times[i])
            {
                return i;
            }
        }

        return n;
    }
};