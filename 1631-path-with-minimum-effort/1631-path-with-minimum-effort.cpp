#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(), m=heights[0].size();

        vector<vector<int>>dist(n, vector<int>(m, INT_MAX));
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>pq;

        dist[0][0]=0;
        pq.push({0, {0, 0}});

        int dirX[4]={-1, 0, 1, 0}, dirY[4]={0, 1, 0, -1};

        while(!pq.empty()) 
        {
            auto [effort, pos]=pq.top();
            pq.pop();

            int x=pos.first, y=pos.second;

            if(x==n-1 && y==m-1)
            { 
                return effort;
            }

            for(int k=0; k<4; k++) 
            {
                int newX=x+dirX[k], newY=y+dirY[k];

                if(newX>=0 && newX<n && newY>=0 && newY<m) 
                {
                    int currentEffort=max(effort, abs(heights[newX][newY]-heights[x][y]));

                    if(currentEffort<dist[newX][newY]) 
                    {
                        dist[newX][newY]=currentEffort;
                        pq.push({currentEffort, {newX, newY}});
                    }
                }
            }
        }

        return 0;
    }
};
