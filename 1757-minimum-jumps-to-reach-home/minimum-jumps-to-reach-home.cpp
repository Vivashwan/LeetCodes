class Solution{
public:
    struct State 
    {
        int position;
        bool backUsed;
    };

    int minimumJumps(vector<int>&forbidden, int a, int b, int x) 
    {
        unordered_set<int>forbiddenSet(forbidden.begin(), forbidden.end());
        unordered_set<string>visited;
        
        queue<State>q;
        q.push({0, false});
        visited.insert("0_0");

        int steps=0;
        int upperLimit=max(x+b, *max_element(forbidden.begin(), forbidden.end()))+a+b;
        
        while(!q.empty()) 
        {
            int size=q.size();
            
            while(size--) 
            {
                State current=q.front();
                q.pop();
                
                int pos=current.position;
                bool backUsed=current.backUsed;
                
                if(pos==x)
                { 
                    return steps;
                }
                
                int forwardPos=pos+a;

                string forwardKey=to_string(forwardPos)+"_0";

                if(forwardPos<=upperLimit && forbiddenSet.find(forwardPos)==forbiddenSet.end() && visited.find(forwardKey)==visited.end()) 
                {
                    visited.insert(forwardKey);
                    q.push({forwardPos, false});
                }
                
                int backwardPos=pos-b;

                string backwardKey=to_string(backwardPos)+"_1";

                if(!backUsed && backwardPos>=0 && forbiddenSet.find(backwardPos)==forbiddenSet.end() && visited.find(backwardKey)==visited.end()) 
                {
                    visited.insert(backwardKey);
                    q.push({backwardPos, true});
                }
            }
            
            steps++;
        }
        
        return -1;
    }
};