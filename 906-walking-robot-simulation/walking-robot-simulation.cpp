class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>set;

        for(auto it: obstacles)
        {
            set.insert(to_string(it[0])+","+to_string(it[1]));
        }

        vector<vector<int>>directions={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int x=0, y=0, maxRes=0, dir=0;

        for(auto it: commands)
        {
            if(it==-2)
            {
                dir=(dir+3)%4;
            }
            else if(it==-1)
            {
                dir=(dir+1)%4;
            }
            else
            {
                for(int i=0; i<it; i++)
                {
                    int newX=x+directions[dir][0];
                    int newY=y+directions[dir][1];

                    if(set.find(to_string(newX)+","+to_string(newY))!=set.end())
                    {
                        break;
                    }

                    x=newX, y=newY;
                    maxRes = max(maxRes, x*x + y*y);
                }
            }
        }

        return maxRes;
    }
};