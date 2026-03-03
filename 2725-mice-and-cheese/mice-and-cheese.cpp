class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n=reward1.size();

        priority_queue<pair<int, int>>pq;

        for(int i=0; i<n; i++)
        {
            pq.push({reward1[i]-reward2[i], i});
        }

        int maxim=0;

        vector<bool>visited(n, false);

        while(!pq.empty() && k>0)
        {
            auto [diff, ind]=pq.top();
            pq.pop();

            maxim+=reward1[ind];
            visited[ind]=true;
            k--;
        }

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                maxim+=reward2[i];
            }
        }

        return maxim;
    }
};