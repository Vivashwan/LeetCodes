class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        vector<int>res;

        int start=customers[0][0];

        for(int i=0; i<n; i++)
        {
            int arrival = customers[i][0], time = customers[i][1];

            if(arrival>start)
            {
                start = arrival;
            }

            start+=time;

            res.push_back(start-arrival);
        }

        double ans = 0;

        for(auto it: res)
        {
            ans+=(double)it;
        }

        return (double)ans/n;
    }
};