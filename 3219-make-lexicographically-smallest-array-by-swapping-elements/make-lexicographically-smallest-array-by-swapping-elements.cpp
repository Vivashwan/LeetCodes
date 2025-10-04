class Solution {
private:
    vector<int>parent, rank;

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
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {  
        int n=nums.size();     

        vector<pair<int, int>>arr;

        arr.reserve(n);

        for(int i=0; i<n; i++)
        {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        parent.resize(n), rank.resize(n, 0);

        iota(parent.begin(), parent.end(), 0);

        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i].first-arr[i-1].first<=limit)
            {
                unite(arr[i-1].second, arr[i].second);
            }
        }

        unordered_map<int, vector<int>>compIndices, compValues;

        for(int i=0; i<n; i++)
        {
            int root=find(i);
            compIndices[root].push_back(i);
            compValues[root].push_back(nums[i]);
        }

        vector<int>res(n);

        for(auto it: compIndices)
        {
            auto indices=it.second;

            sort(indices.begin(), indices.end());

            auto values=compValues[it.first];

            sort(values.begin(), values.end());

            for(int i=0; i<indices.size(); i++)
            {
                res[indices[i]]=values[i];
            }
        }

        return res;
    }
};