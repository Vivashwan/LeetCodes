class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int res=INT_MIN;

        int currMin=arrays[0][0], currMax=arrays[0].back();

        for(int i=1; i<arrays.size(); i++)
        {
            int newMin=arrays[i][0], newMax=arrays[i].back();

            res=max(res, abs(currMax-newMin));
            res=max(res, abs(newMax-currMin));

            currMin=min(currMin, newMin);
            currMax=max(currMax, newMax);
        }

        return res;
    }
};