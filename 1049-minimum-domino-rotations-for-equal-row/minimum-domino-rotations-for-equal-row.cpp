class Solution {
public:
    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop=0, rotateBottom=0;

        for(int i=0; i<tops.size(); i++) 
        {
            if(tops[i]!=x && bottoms[i]!=x) 
            {
                return -1;
            }
            else if(tops[i]!=x)
            { 
                rotateTop++;
            }
            else if(bottoms[i]!=x)
            { 
                rotateBottom++;
            }
        }

        return min(rotateTop, rotateBottom);
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans=check(tops[0], tops, bottoms);

        if(ans!=-1)
        { 
            return ans;
        }

        return check(bottoms[0], tops, bottoms);
    }
};
