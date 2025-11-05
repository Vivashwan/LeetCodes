class Solution {
private:
    bool func(int n, vector<int>&res, vector<int>&used)
    {
        int i=0;

        while(i<2*n-1 && res[i]!=0)
        {
            i++;
        }

        if(i==2*n-1)
        {
            return true;
        }

        for(int x=n; x>=1; --x)
        {
            if(used[x])
            { 
                continue;
            }

            if(x==1)
            {
                used[x]=1;
                res[i]=x;
                if(func(n, res, used))
                {
                    return true;
                }
                res[i]=0;
                used[x]=0;
            }
            else
            {
                int j=i+x;
                if(j<(int)res.size() && res[j]==0) 
                {
                    res[i]=res[j]=x;
                    used[x]=1;

                    if(func(n, res, used))
                    {
                        return true;
                    }

                    res[i]=res[j]=0;
                    used[x]=0;
                }
            }
        }

        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int>res(2*n-1, 0), used(n+1, 0);

        func(n, res, used);

        return res;
    }
};