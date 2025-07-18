class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(), intervals.end());

        vector<int>v=intervals[0];

        int size=1;

        for(int i=1; i<n; i++)
        {
            if(intervals[i][0]>v[0] && intervals[i][1]>v[1])
            {
                size++;
            }

            if(intervals[i][1]>v[1])
            {
                v=intervals[i];
            }
        }

        return size;
    }
};