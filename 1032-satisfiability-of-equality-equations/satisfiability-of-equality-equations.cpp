class Solution {
private:
    unordered_map<char, char>parent;
    unordered_map<char, int>rank;

    char find(char x)
    {
        while(parent[x]!=x)
        {
            parent[x]=parent[parent[x]];
            x=parent[x];
        }

        return x;
    }

    void unite(char x, char y)
    {
        char px=find(x), py=find(y);

        if(px==py)
        {
            return;
        }
        else if(rank[px]<rank[py])
        {
            parent[px]=py;
        }
        else if(rank[px]>rank[py])
        {
            parent[py]=px;
        }
        else
        {
            parent[py]=px;
            rank[px]++;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();

        for(char c='a'; c<='z'; c++) 
        {
            parent[c]=c;
            rank[c]=0;
        }

        for(int i=0; i<n; i++)
        {
            char start=equations[i][0], end=equations[i][3], sign=equations[i][1];

            if(sign=='=')
            {
                unite(start, end);
            }
            
        }

        for(int i=0; i<n; i++)
        {
            char start=equations[i][0], end=equations[i][3], sign=equations[i][1];

            if(sign=='!' && find(start)==find(end))
            {
                return false;
            }
            
        }
        
        return true;
    }
};