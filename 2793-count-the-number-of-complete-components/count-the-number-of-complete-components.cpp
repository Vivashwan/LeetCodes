class Solution {
private:
    vector<int>parent;

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

        if(px<py)
        {
            parent[py]=px;
        }
        else parent[px]=py;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        
        for(int i=0; i<n; i++)
        {
            parent[i]=i;
        }

        for(auto it: edges)
        {
            unite(it[0], it[1]);
        }

        vector<int>size(n, 0), edgeCount(n, 0);

        for(int i=0; i<n; i++)
        {
            size[find(i)]++;
        }

        for(auto it: edges)
        {
            edgeCount[find(it[0])]++;
        }

        int count=0;

        for(int i=0; i<n; i++)
        {
            if(parent[i]==i)
            {
                if(edgeCount[i]==size[i]*(size[i]-1)/2)
                {
                    count++;
                }
            }
        }

        return count;
    }
};