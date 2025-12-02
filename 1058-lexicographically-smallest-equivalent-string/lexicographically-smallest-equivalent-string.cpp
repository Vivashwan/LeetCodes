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

        if(px<py)
        {
            parent[py]=px;
        }
        else if(px>py)
        {
            parent[px]=py;
        }
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();

        parent.resize(26);
        iota(parent.begin(), parent.end(), 0);

        for(int i=0; i<n; i++)
        {
            unite(s1[i]-'a', s2[i]-'a');
        }

        string res=baseStr;

        for(int i=0; i<res.length(); i++)
        {
            res[i]=find(baseStr[i]-'a')+'a';
        }        

        return res;
    }
};