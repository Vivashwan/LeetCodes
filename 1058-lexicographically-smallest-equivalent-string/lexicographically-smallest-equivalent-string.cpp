class Solution {
private:
    int parent[26];

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
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.length();

        for(int i=0; i<26; i++)
        {
            parent[i]=i;
        }

        for(int i=0; i<n; i++)
        {
            unite(s1[i]-'a', s2[i]-'a');
        }

        string res=baseStr;

        for(int i=0; i<baseStr.length(); i++)
        {
            res[i]=find(baseStr[i]-'a')+'a';
        }

        return res;
    }
};