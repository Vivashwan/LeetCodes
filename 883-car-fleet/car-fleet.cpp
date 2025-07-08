class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();

        vector<pair<int, int>>adj(n);

        for(int i=0; i<n; i++)
        {
            adj[i]={position[i], speed[i]};
        }

        sort(adj.begin(), adj.end());

        stack<double>st;

        for(auto it=adj.rbegin(); it!=adj.rend(); it++)
        {
            double dist=target-it->first, time=(double)dist/it->second;

            if(st.empty() || time>st.top())
            {
                st.push(time);
            }
        }   

        return st.size();
    }
};