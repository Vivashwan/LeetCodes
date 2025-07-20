class Solution {
private:
    int func(int ind, int& ans, int n, vector<bool>&visited)
    {
        if(ind==n)
        {
            ans++;
        }

        for(int num=1; num<=n; num++)
        {
            if(!visited[num])
            {
                if((ind+1)%num==0 || (num%(ind+1)==0))
                {
                    visited[num]=true;
                    func(ind+1, ans, n, visited);
                    visited[num]=false;
                }
            }
        }

        return ans;
    }
public:
    int countArrangement(int n) {
        vector<bool>visited(n, false);

        int ans=0;

        func(0, ans, n, visited);

        return ans;
    }
};