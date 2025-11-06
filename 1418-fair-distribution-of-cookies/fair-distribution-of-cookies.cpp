class Solution {
public:
    int res=INT_MAX;

    void backtrack(vector<int>& cookies, vector<int>&dist, int i, int k) 
    {
        if(i==cookies.size()) 
        {
            res=min(res, *max_element(dist.begin(), dist.end()));
            return;
        }

        for(int j=0; j<k; j++) 
        {
            dist[j]+=cookies[i];

            if(dist[j]<res)
            {    
                backtrack(cookies, dist, i+1, k);
            }

            dist[j]-=cookies[i];

            if(dist[j]==0)
            { 
                break;
            }
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>dist(k, 0);
        backtrack(cookies, dist, 0, k);
        
        return res;
    }
};