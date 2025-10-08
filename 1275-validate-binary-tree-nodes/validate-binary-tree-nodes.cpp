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
        if(size[px]>size[py])
        { 
            parent[py]=px;
        }
        else if(size[px]<size[py])
        { 
            parent[px]=py;
        }
        else 
        { 
            parent[py]=px; 
            size[px]+=size[py];
        }
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>indegree(n, 0);
        
        parent.resize(n);
        size.assign(n, 1);

        iota(parent.begin(), parent.end(), 0);

        for(int i=0; i<n; i++) 
        {
            if(leftChild[i]!=-1)
            { 
                indegree[leftChild[i]]++;
            }

            if(rightChild[i]!=-1) 
            {
                indegree[rightChild[i]]++;
            }
        }

        for(int i=0; i<n; i++) 
        {
            if(indegree[i]>1)
            { 
                return false;
            }
        }

        int rootCount=0;

        for(int i=0; i<n; i++) 
        {
            if(indegree[i]==0)
            { 
                rootCount++;
            }
        }

        if(rootCount!=1) 
        {
            return false;
        }

        for(int i=0; i<n; i++) 
        {
            if(leftChild[i]!=-1) 
            {
                if(find(i)==find(leftChild[i])) 
                {
                    return false;
                }
                unite(i, leftChild[i]);
            }

            if(rightChild[i]!=-1) 
            {
                if(find(i)==find(rightChild[i]))
                { 
                    return false;
                }

                unite(i, rightChild[i]);
            }
        }

        int root=find(0);

        for(int i=1; i<n; i++) 
        {
            if(find(i)!=root)
            { 
                return false;
            }
        }

        return true;
    }
};
