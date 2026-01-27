class Solution {
private:
    static bool myCmp(vector<int>&a, vector<int>&b)
    {
        if(a[1]==b[1])
        {
            return a[0]<b[0];
        }

        return a[1]<b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();

        sort(intervals.begin(), intervals.end(), myCmp);

        int count=0, end=intervals[0][1];

        for(int i=1; i<n; i++)
        {
            if(end<=intervals[i][0])
            {
                end=intervals[i][1];
            }
            else
            {
                count++;
            }
        }

        return count;
    }
};