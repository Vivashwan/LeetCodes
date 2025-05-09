class Solution {
private:
    static bool myCmp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();

        sort(points.begin(), points.end(), myCmp);

        int count=1, end=points[0][1];

        for(int i=1; i<n; i++)
        {
            if(points[i][0]>end) 
            {
                count++;
                end=points[i][1];
            }
        }

        return count;
    }
};