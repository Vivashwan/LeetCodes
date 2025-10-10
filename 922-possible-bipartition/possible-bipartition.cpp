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
        else if(size[px]<size[py])
        {
            parent[px]=py;
        }
        else if(size[px]>size[py])
        {
            parent[py]=px;
        }
        else
        {
            parent[py]=px;
            size[px]++;
        }
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        parent.resize(n*2+1);
        size.resize(n*2+1, 1);

        iota(parent.begin(), parent.end(), 0);

        for(auto it: dislikes)
        {
            int a=it[0], b=it[1];

            if(find(a)==find(b))
            {
                return false;
            }

            unite(a, b+n);
            unite(a+n, b);
        }

        return true;
    }
};