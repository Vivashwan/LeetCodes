class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>siml(1001, capacity);

        for(auto it: trips)
        {
            for(int i=it[1]; i<it[2]; i++)
            {
                if(siml[i]-it[0]<0)
                {
                    return false;
                }
                else siml[i]-=it[0];
            }
        }

        return true;
    }
};