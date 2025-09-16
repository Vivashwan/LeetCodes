class Solution {
    void isSurroundedBy0s(int row, int col, vector<vector<char>>&board)
    {
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] != 'O')
        {
            return;
        }

        board[row][col] = 'S';

        isSurroundedBy0s(row-1, col, board);
        isSurroundedBy0s(row+1, col, board);
        isSurroundedBy0s(row, col+1, board);
        isSurroundedBy0s(row, col-1, board);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i=0; i<n; i++)
        {
            isSurroundedBy0s(i, 0, board);
            isSurroundedBy0s(i, m-1, board);
        }

        for(int i=0; i<m; i++)
        {
            isSurroundedBy0s(0, i, board);
            isSurroundedBy0s(n-1, i, board);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                else if(board[i][j]=='S')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};