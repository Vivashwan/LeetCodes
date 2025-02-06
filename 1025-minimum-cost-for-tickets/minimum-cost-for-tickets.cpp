class Solution {
private:
    int func(vector<int>&days, vector<int>&costs, int n, int ind, vector<int>&dp)
    {
        if(ind>=n)
        {
            return 0;
        }

        if(dp[ind]!=-1)
        {
            return dp[ind];
        }

        int expenseFor1DayPass = costs[0]+func(days, costs, n, ind+1, dp);

        int j=ind;

        while(j<n && days[j]<days[ind]+7)
        {
            j++;
        }

        int expenseFor7DayPass = costs[1]+func(days, costs, n, j, dp);

        j=ind;

        while(j<n && days[j]<days[ind]+30)
        {
            j++;
        }

        int expenseFor30DayPass = costs[2]+func(days, costs, n, j, dp);

        return dp[ind] = min({expenseFor1DayPass, expenseFor7DayPass, expenseFor30DayPass});

    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int>dp(n, -1);

        return func(days, costs, n, 0, dp);
    }
};