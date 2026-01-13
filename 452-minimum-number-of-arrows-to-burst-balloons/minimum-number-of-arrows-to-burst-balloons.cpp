class Solution {
public:
    // static bool myCmp(vector<int>&a, vector<int>&b)
    // {
    //     return a[1]<b[1];
    // }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n=points.size();
        int val=points[0][1];
        int count=1;

        for(int i=1; i<n; i++)
        {
            if(val>=points[i][0])
            {
                val=min(val, points[i][1]);
            }
            else
            {
                count++;
                val=points[i][1];
            }
        }

        return count;
    }
};