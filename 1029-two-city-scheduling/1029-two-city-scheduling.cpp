class Solution {
private:
    static bool myCmp(vector<int>&a, vector<int>&b)
    {
        return (a[0] - a[1]) < (b[0] - b[1]);
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), myCmp);

        int total=0;

        int n=costs.size();

        for(int i=0; i<n/2; i++)
        {
            total+=costs[i][0];
        }

        for(int i=n/2; i<n; i++)
        {
            total+=costs[i][1];
        }

        return total;
    }
};