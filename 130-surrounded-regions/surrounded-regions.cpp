class Solution {
private:
    vector<int>parent, size;

    int find(int x)
    {
        while(parent[x]!=x)
        {
            parent[x]=parent[parent[x]];
            x=parent[x];
        }

        return x;
    }

    void unite(int x, int y)
    {
        int px=find(x), py=find(y);

        if(px==py)
        {
            return;
        }
        else if(size[py]>size[px])
        {
            parent[px]=py;
        }
        else if(size[py]<size[px])
        {
            parent[py]=px;
        }
        else 
        {
            parent[py]=px;
            size[px]+=size[py];
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();

        parent.resize(n*m+1);
        size.resize(n*m+1, 1);

        int dummy=n*m;

        iota(parent.begin(), parent.end(), 0);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                {
                    if(i==0 || i==n-1 || j==m-1 || j==0)
                    {
                        unite(i*m+j, dummy);
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                {
                    int id=i*m+j;

                    if(i+1<n && board[i+1][j]=='O')
                    {
                        unite(id, (i+1)*m+j);
                    }

                    if(j-1>=0 && board[i][j-1]=='O')
                    {
                        unite(id, i*m+j-1);
                    }
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                {
                    if(find(i*m+j)!=find(dummy))
                    {
                        board[i][j]='X';
                    }
                }
            }
        }
    }
};