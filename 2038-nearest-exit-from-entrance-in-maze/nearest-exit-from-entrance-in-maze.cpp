class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size(), m = maze[0].size(), steps = 0;

        queue<pair<int, int>>q;

        q.push({entrance[0], entrance[1]});

        maze[entrance[0]][entrance[1]] = '+';

        vector<pair<int, int>>dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

        while(!q.empty())
        {
            int size = q.size();
            steps++;

            for(int i=0; i<size; i++)
            {
                auto [r, c] = q.front();
                q.pop();

                for(auto [rd, cd]: dirs)
                {
                    int newRow = rd+r, newCol = cd+c;

                    if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && maze[newRow][newCol]=='.')
                    {
                        if(newRow==0 || newCol == 0 || newRow == n-1 || newCol == m-1)
                        {
                            return steps;
                        }

                        maze[newRow][newCol] = '+';
                        q.push({newRow, newCol});
                    }
                }
            }
        }

        return -1;
    }
};