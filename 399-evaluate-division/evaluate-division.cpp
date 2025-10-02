class Solution {
private:
    unordered_map<string, string>parent;
    unordered_map<string, double>weight;

    string find(string x)
    {
        if(parent.find(x)==parent.end())
        {
            parent[x]=x;
            weight[x]=1.0;
        }

        if(parent[x]!=x)
        {
            string org=parent[x];
            parent[x]=find(org);
            weight[x]*=weight[org];
        }

        return parent[x];
    }

    void unite(string x, string y, double val)
    {
        string rootX=find(x), rootY=find(y);

        if(rootX==rootY)
        {
            return;
        }

        parent[rootX]=rootY;

        weight[rootX]=weight[y]*val/weight[x];
    }

    double divide(string x, string y)
    {
        if(parent.find(x)==parent.end() || parent.find(y)==parent.end())
        {
            return -1.0;
        }

        string rootX=find(x), rootY=find(y);

        if(rootX!=rootY)
        {
            return -1.0;
        }

        return weight[x]/weight[y];
    }

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0; i<equations.size(); i++)
        {
            string a=equations[i][0], b=equations[i][1];

            double val=values[i];

            unite(a, b, val);
        }

        vector<double>res;

        for(auto it: queries)
        {
            res.push_back(divide(it[0], it[1]));
        }

        return res;
    }
};