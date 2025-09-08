class Solution {
private:
    void func(vector<vector<char>>&board, vector<vector<bool>>&visited, int i, int j, int n, int m)
    {
        visited[i][j]=true;

        int dirX[4]={-1, 0, 0, 1}, dirY[4]={0, 1, -1, 0};

        for(int k=0; k<4; k++)
        {
            int newX=i+dirX[k], newY=j+dirY[k];

            if(newX>=0 && newX<n && newY>=0 && newY<m && board[newX][newY]=='X' && !visited[newX][newY])
            {
                func(board, visited, newX, newY, n, m);
            }
        }
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();

        int count=0;

        vector<vector<bool>>visited(n, vector<bool>(m, false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='X' && !visited[i][j])
                {
                    count++;
                    func(board, visited, i, j, n, m);
                }
            }
        }        

        return count;
    }
};