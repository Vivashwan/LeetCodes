class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();

        int minCost = 0;

        for(int i=1; i<n;)
        {
            if(colors[i]!=colors[i-1])
            {
                i++;
            }
            else
            {
                int sum = neededTime[i-1];
                int maxi = neededTime[i-1];

                while(i<n && colors[i-1]==colors[i])
                {
                    sum+=neededTime[i];

                    maxi = max(maxi, neededTime[i]);
                    i++;
                }

                minCost+=(sum-maxi);
            }
        }

        return minCost;
    }
};