class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, vector<int>>mp;

        for(auto it: reservedSeats) 
        {
            mp[it[0]].push_back(it[1]);
        }

        int ans = 2*(n-mp.size());  

        for(auto it: mp) 
        {
            auto seats = it.second;

            bool isLeftAisle=false, isRightAisle=false, isMiddle=false;

            for(int seat: seats) 
            {
                if(seat>=2 && seat<=5)
                {    
                    isLeftAisle = true;
                }

                if(seat>=6 && seat<=9)
                {    
                    isRightAisle = true;
                }

                if(seat>=4 && seat<=7)
                {    
                    isMiddle = true;
                }

                if(isLeftAisle && isRightAisle && isMiddle)
                {    
                    break;
                }
            }

            if(!isLeftAisle)
            {    
                ans+=1;
            }

            if(!isRightAisle)
            {    
                ans+=1;
            }

            if(isLeftAisle && isRightAisle && !isMiddle)
            {    
                ans+=1;
            }
        }

        return ans;
    }
};