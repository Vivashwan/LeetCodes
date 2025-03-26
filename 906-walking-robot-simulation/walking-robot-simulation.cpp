class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>obstacleSet;

        for(auto obs: obstacles) 
        {
            obstacleSet.insert(to_string(obs[0]) + "," + to_string(obs[1]));
        }
        
        vector<vector<int>>directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        int x=0, y=0, dir=0, maxDist=0;

        for(int cmd: commands) 
        {
            if(cmd == -2) 
            {
                dir = (dir + 3) % 4;
            } 
            else if(cmd == -1)
            {
                dir = (dir + 1) % 4;
            } 
            else 
            { 
                for(int i=0; i<cmd; i++) 
                {
                    int newX = x+directions[dir][0];
                    int newY = y+directions[dir][1];
                    if(obstacleSet.find(to_string(newX) + "," + to_string(newY)) != obstacleSet.end()) {
                        break;
                    }

                    x=newX, y=newY;
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }
        
        return maxDist;
    }
};