class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());

        int ans=0, total=0, endInd=0;

        for(int startInd=0; startInd<tiles.size(); startInd++)
        {
            int start = tiles[startInd][0], end = start+carpetLen-1;

            while(endInd<tiles.size() && tiles[endInd][1]<end)
            {
                total+=tiles[endInd][1]-tiles[endInd][0]+1;
                endInd++;
            }

            if(endInd==tiles.size() || tiles[endInd][0]>end)
            {
                ans = max(ans, total);
            }
            else ans = max(ans, total+(end-tiles[endInd][0]+1));

            total-=tiles[startInd][1]-tiles[startInd][0]+1;
        }

        return ans;
    }
};