class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>start, end;

        for(auto it: intervals)
        {
            start.push_back(it[0]);
            end.push_back(it[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int count=0, j=0;

        for(auto it: start)
        {
            if(it>end[j])
            {
                j++;
            }
            else count++;
        }

        return count;
    }
};