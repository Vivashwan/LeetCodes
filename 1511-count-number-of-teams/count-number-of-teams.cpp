class SegmentTree {
    vector<int>tree;
    int n;

public:
    SegmentTree(int size) 
    {
        n=size;
        tree.resize(4*n, 0);
    }

    void update(int node, int start, int end, int idx, int val) 
    {
        if(start==end) 
        {
            tree[node]+=val;
            return;
        }

        int mid=(start+end)/2;

        if(idx<=mid)
        { 
            update(2*node+1, start, mid, idx, val);
        }
        else
        { 
            update(2*node+2, mid+1, end, idx, val);
        }

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    int query(int node, int start, int end, int L, int R) 
    {
        if(R<start || end<L)
        { 
            return 0;
        }

        if(L<=start && end<=R)
        {
            return tree[node];
        }

        int mid=(start+end)/2;

        return query(2*node+1, start, mid, L, R)+query(2*node+2, mid+1, end, L, R);
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();

        if(n<3) 
        {
            return 0;
        }

        vector<int>sorted=rating;

        sort(sorted.begin(), sorted.end());

        for(int &r: rating)
        {    
            r=lower_bound(sorted.begin(), sorted.end(), r)-sorted.begin()+1;
        }

        vector<int>lessLeft(n), greaterLeft(n), lessRight(n), greaterRight(n);

        SegmentTree segL(n);

        for(int j=0; j<n; j++) 
        {
            lessLeft[j]=segL.query(0, 0, n-1, 0, rating[j]-2);
            greaterLeft[j]=segL.query(0, 0, n-1, rating[j], n-1);
            segL.update(0, 0, n-1, rating[j]-1, 1);
        }

        SegmentTree segR(n);

        for(int j=n-1; j>=0; j--) 
        {
            lessRight[j]=segR.query(0, 0, n-1, 0, rating[j]-2);
            greaterRight[j]=segR.query(0, 0, n-1, rating[j], n-1);
            segR.update(0, 0, n-1, rating[j]-1, 1);
        }

        long long total=0;

        for(int j=0; j<n; j++)
        {   
            total+=1LL*lessLeft[j]*greaterRight[j]+1LL*greaterLeft[j]*lessRight[j];
        }

        return (int)total;
    }
};