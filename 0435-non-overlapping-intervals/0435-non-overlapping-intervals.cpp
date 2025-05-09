class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>&a, vector<int>&b)
        {
            return a[1]<b[1];
        });

        int count=0, end=INT_MIN;

        for(auto it: intervals) 
        {
            if(it[0]>=end) 
            {
                end=it[1];
            } 
            else count++;
        }

        return count;
    }
};
