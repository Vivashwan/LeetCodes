class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int totalGas=0, totalCost=0, start=0, currFuel=0;

        for(int i=0; i<n; i++)
        {
            totalGas+=gas[i], totalCost+=cost[i];

            currFuel+=gas[i]-cost[i];

            if(currFuel<0)
            {
                start=i+1, currFuel=0;
            }
        }

        if(totalGas<totalCost)
        {
            return -1;
        }
        
        return start;
    }
};