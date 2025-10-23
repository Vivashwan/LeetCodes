class SegmentTree{
    vector<int>tree;
    int n;
public:
    SegmentTree(int size)
    {
        n=size;
        tree.resize(4*n, 0);

        build(0, 0, n-1);
    }

    void build(int node, int start, int end)
    {
        if(start==end)
        {
            tree[node]=1;
            return;
        }

        int mid=(start+end)/2;

        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    int query(int node, int start, int end, int k)
    {
        if(start==end)
        {
            return start;
        }

        int mid=(start+end)/2;
        int left=tree[2*node+1];

        if(k<=left)
        {
            return query(2*node+1, start, mid, k);
        }
        else return query(2*node+2, mid+1, end, k-left);
    }

    void update(int node, int start, int end, int ind)
    {
        if(start==end)
        {
            tree[node]=0;
            return;
        }

        int mid=(start+end)/2;

        if(ind<=mid)
        {
            update(2*node+1, start, mid, ind);
        }
        else
        {
            update(2*node+2, mid+1, end, ind);
        }

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }
};
class Solution {
private:
    static bool myCmp(vector<int>&a, vector<int>&b)
    {
        if(a[0]==b[0])
        { 
            return a[1]>b[1];
        }

        return a[0]<b[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();

        sort(people.begin(), people.end(), myCmp);

        vector<vector<int>>res(n, vector<int>(2, 0));

        SegmentTree seg(n);

        for(auto it: people)
        {
            int ind=seg.query(0, 0, n-1, it[1]+1);
            res[ind]=it;
            seg.update(0, 0, n-1, ind);
        }

        return res;
    }
};