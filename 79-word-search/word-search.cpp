class Solution {
private:
    bool dfs(vector<vector<char>>&board, string&word, int r, int c, int index) 
    {
        if(index==word.size())
        { 
            return true;
        }

        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c]!=word[index]) 
        {    
            return false;
        }

        char temp=board[r][c];
        board[r][c]='#';

        bool found=dfs(board, word, r+1, c, index+1) ||
                    dfs(board, word, r-1, c, index+1) ||
                    dfs(board, word, r, c+1, index+1) ||
                    dfs(board, word, r, c-1, index+1);

        board[r][c]=temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size(), cols=board[0].size();

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(dfs(board, word, i, j, 0))
                { 
                    return true;
                }
            }
        }

        return false;
    }
};
