class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double ans = 0;
        int start=customers[0][0];

        for(int i=0; i<n; i++)
        {
            int arrival = customers[i][0], time = customers[i][1];

            if(arrival>start)
            {
                start = arrival;
            }

            start+=time;

            ans+=(double)(start-arrival);
        }

        return (double)ans/n;
    }
};