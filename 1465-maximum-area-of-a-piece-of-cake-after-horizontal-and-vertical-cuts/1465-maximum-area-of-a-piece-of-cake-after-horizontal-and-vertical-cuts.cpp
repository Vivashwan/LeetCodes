class Solution {
private:
    long MOD = 1e9+7;
    long func(vector<int>&coordinates, int coordinateLength)
    {
        sort(coordinates.begin(), coordinates.end());

        int maxim = coordinates[0];

        for(int i=1; i<coordinates.size(); i++)
        {
            maxim = max(maxim, coordinates[i]-coordinates[i-1]);
        }

        maxim = max(maxim, coordinateLength-coordinates.back());

        return maxim;
    }
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        long x = func(horizontalCuts, h);
        long y = func(verticalCuts, w);

        return (x*y)%MOD;
    }
};