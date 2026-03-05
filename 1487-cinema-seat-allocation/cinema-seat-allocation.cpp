class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>>mp;

        for(auto it: reservedSeats)
        {
            mp[it[0]].push_back(it[1]);
        }

        int res=2*(n-mp.size());

        for(auto it: mp)
        {
            auto seats=it.second;

            bool isLeftBlocked=false, isRightBlocked=false, isMiddle=false;

            for(auto seat: seats)
            {
                if(seat>=2 && seat<=5)
                {
                    isLeftBlocked=true;
                }
                
                if(seat>=4 && seat<=7)
                {
                    isMiddle=true;
                }

                if(seat>=6 && seat<=9)
                {
                    isRightBlocked=true;
                }

                if(isLeftBlocked && isMiddle && isRightBlocked)
                {
                    break;
                }
            }

            if(!isLeftBlocked)
            {
                res++;
            }

            if(!isRightBlocked)
            {
                res++;
            }

            if(isLeftBlocked && isRightBlocked && !isMiddle)
            {
                res++;
            }
        }

        return res;
    }
};