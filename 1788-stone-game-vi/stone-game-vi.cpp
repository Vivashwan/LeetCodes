class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size();
        vector<vector<int>>v;

        for(int i=0; i<n; i++)
        {
            v.push_back({aliceValues[i]+bobValues[i], aliceValues[i], bobValues[i]});
        }

        sort(v.begin(), v.end(), greater<vector<int>>());

        int alice=0, bob=0;

        for(int i=0; i<n; i++)
        {
            if(i%2==0)
            {
                alice+=v[i][1];
            }
            else bob+=v[i][2];
        }

        if(alice==bob)
        {
            return 0;
        }
        else if(alice>bob)
        {
            return 1;
        }
        else return -1;
    }
};