class Solution {
private:
    bool isFound=false;

    void func(vector<vector<char>>& board, string& word, vector<vector<int>>& visited, int n, int m, int l, int row, int col, int ind)
    {
        if(ind==l)
        {
            isFound=true;
            return;
        }

        int dirX[4]={1, 0, -1, 0};
        int dirY[4]={0, 1, 0, -1};

        for(int k=0; k<4; k++)
        {
            int newDirX=row+dirX[k], newDirY=col+dirY[k];

            if(newDirX>=0 && newDirX<n && newDirY>=0 && newDirY<m && !visited[newDirX][newDirY] && board[newDirX][newDirY]==word[ind])
            {
                visited[newDirX][newDirY]=true;
                func(board, word, visited, n, m, l, newDirX, newDirY, ind+1);
                visited[newDirX][newDirY]=false;
            }
        }
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size(), l=word.length();

        vector<vector<int>>visited(n, vector<int>(m, false));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]==word[0])
                {
                    visited[i][j]=true;
                    func(board, word, visited, n, m, l, i, j, 1);
                    visited[i][j]=false;
                }
            }
        }

        return isFound;
    }
};