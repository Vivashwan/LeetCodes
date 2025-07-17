class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>radiant, dire;

        for(int i=0; i<senate.size(); i++)
        {
            if(senate[i]=='R')
            {
                radiant.push(i);
            }
            else dire.push(i);
        }

        while(!radiant.empty() && !dire.empty())
        {
            int senateR=radiant.front(); radiant.pop();
            int senateD=dire.front(); dire.pop();

            if(senateR<senateD)
            {
                radiant.push(senateR+senate.size());
            }
            else dire.push(senateD+senate.size());
        }

        return radiant.empty() ? "Dire":"Radiant";
    }
};