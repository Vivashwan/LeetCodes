class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>res(n, 0);

        for(auto it: bookings)
        {
            for(int i=it[0]-1; i<it[1]; i++)
            {
                res[i]+=it[2];
            }
        }

        return res;
    }
};