class Solution {
private:
    bool isInside(int x, int y, int x1, int y1, int r)
    {
        if (x > x1 + r || x < x1 - r || y > y1 + r || y < y1 - r)
        {    
            return false;
        }

        return pow(x-x1, 2) + pow(y-y1, 2) <= pow(r, 2);
    }
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size(), m = points.size();

        vector<int>res(n, 0);

        for(int i=0; i<n; i++)
        {
            int x1 = queries[i][0], y1 = queries[i][1], r = queries[i][2];

            for(int j=0; j<m; j++)
            {
                int x = points[j][0], y = points[j][1];

                if(isInside(x, y, x1, y1, r))
                {
                    res[i]++;
                }
            }
        }

        return res;
    }
};