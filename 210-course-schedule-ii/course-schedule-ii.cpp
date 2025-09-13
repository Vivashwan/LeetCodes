class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>mp;

        vector<int>inDegree(numCourses, 0);

        for(auto it: prerequisites)
        {
            mp[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }

        queue<int>q;

        for(int i=0; i<numCourses; i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }

        vector<int>res;

        while(!q.empty())
        {
            int course=q.front();
            q.pop();

            res.push_back(course);

            for(auto it: mp[course])
            {
                inDegree[it]--;

                if(inDegree[it]==0)
                {
                    q.push(it);
                }
            }
        }

        if(res.size()==numCourses)
        {
            return res;
        }
        
        return {};
    }
};