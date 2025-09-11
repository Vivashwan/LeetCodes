class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(deadends.begin(), deadends.end()), visited;
        
        string start="0000";

        if(dead.count(start))
        { 
            return -1;
        }

        queue<pair<string, int>>q;
        
        q.push({start, 0});
        visited.insert(start);

        while(!q.empty()) 
        {
            auto [curr, steps]=q.front();
            q.pop();

            if(curr==target)
            { 
                return steps;
            }

            for(int i=0; i<4; i++) 
            {
                string next=curr;
                
                next[i]=(curr[i]-'0'+1)%10+'0';

                if(!dead.count(next) && !visited.count(next)) 
                {
                    q.push({next, steps+1});

                    visited.insert(next);
                }
                
                next[i]=(curr[i]-'0'+9)%10+'0';

                if(!dead.count(next) && !visited.count(next)) 
                {
                    q.push({next, steps+1});
                    visited.insert(next);
                }
            }
        }

        return -1;
    }
};