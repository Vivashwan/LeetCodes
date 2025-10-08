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
        else if(size[px]>size[py])
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
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();

        parent.resize(n);
        size.resize(n, 0);

        iota(parent.begin(), parent.end(), 0);

        unordered_map<int,int>mp;

        for(int i=0; i<n; i++) 
        {
            if(mp.find(nums[i])!=mp.end())
            { 
                continue;
            }

            mp[nums[i]]=i;
        }

        for(auto &p: mp) 
        {
            int num=p.first, idx=p.second;

            if(mp.count(num+1)) 
            {
                unite(idx, mp[num+1]);
            }
        }

        unordered_map<int, int>compSize;

        for(int i=0; i<n; i++)
        {
            compSize[find(i)]++;
        }

        int count=0;

        for(auto it: compSize)
        {
            count=max(count, it.second);
        }

        return count;
    }
};