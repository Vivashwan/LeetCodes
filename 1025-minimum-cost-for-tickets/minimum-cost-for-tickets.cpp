class Solution {
private:
    int func(vector<int>&days, vector<int>&costs, int n, vector<int>&dp)
    {
        for(int ind=n-1; ind>=0; ind--)
        {
            int expenseFor1DayPass = costs[0]+dp[ind+1];

            int j=ind;

            while(j<n && days[j]<days[ind]+7)
            {
                j++;
            }

            int expenseFor7DayPass = costs[1]+dp[j];

            j=ind;

            while(j<n && days[j]<days[ind]+30)
            {
                j++;
            }

            int expenseFor30DayPass = costs[2]+dp[j];

            dp[ind] = min({expenseFor1DayPass, expenseFor7DayPass, expenseFor30DayPass});

        }

        return dp[0];
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();

        vector<int>dp(n+1, 0);

        return func(days, costs, n, dp);
    }
};