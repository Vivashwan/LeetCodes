#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        int limit = max(x, *max_element(forbidden.begin(), forbidden.end()))+a+b;
        vector<vector<int>> dp(limit+1, vector<int>(2, INT_MAX));
        unordered_set<int>s(forbidden.begin(), forbidden.end());

        queue<pair<int, bool>> q; 
        q.push({0, true});
        dp[0][1] = 0; 

        while(!q.empty()) 
        {
            auto [pos, canMoveBack] = q.front();
            q.pop();

            int jumps = dp[pos][canMoveBack];

            if(pos==x)
            { 
                return jumps;
            }

            int forward = pos+a;
            if(forward<=limit && !s.count(forward) && dp[forward][1]==INT_MAX) 
            {
                dp[forward][1] = jumps+1;
                q.push({forward, true});
            }

            int backward = pos-b;
            if(canMoveBack && backward>=0 && !s.count(backward) && dp[backward][0]==INT_MAX) 
            {
                dp[backward][0] = jumps+1;
                q.push({backward, false});
            }
        }

        return -1; 
    }
};
