class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>inDegree(numCourses, 0);
        
        for(auto& pre: prerequisites) 
        {
            int dest=pre[0];
            int src=pre[1];
            graph[src].push_back(dest);

            inDegree[dest]++;
        }
        
        queue<int>q;
        
        for(int i=0; i<numCourses; i++) 
        {
            if (inDegree[i]==0)
            {    
                q.push(i);
            }
        }
        
        int visitedCourses=0;
        
        while(!q.empty()) 
        {
            int course=q.front();
            q.pop();

            visitedCourses++;
            
            for(int neighbor: graph[course]) 
            {
                inDegree[neighbor]--;

                if(inDegree[neighbor]==0)
                {    
                    q.push(neighbor);
                }
            }
        }
        
        return visitedCourses==numCourses;
    }
};
