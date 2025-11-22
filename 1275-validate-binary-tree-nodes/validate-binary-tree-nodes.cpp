class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int>inDegree(n, 0);

        for(int i=0; i<n; i++)
        {
            if(leftChild[i]!=-1)
            {
                inDegree[leftChild[i]]++;
            }

            if(rightChild[i]!=-1)
            {
                inDegree[rightChild[i]]++;
            }
        }

        int root=-1;

        for(int i=0; i<n; i++)
        {
            if(inDegree[i]==0)
            {
                if(root==-1)
                {
                    root=i;
                }
                else return false;
            }
        }

        if(root==-1)
        {
            return false;
        }

        vector<bool>visited(n, false);
        queue<int>q;

        q.push(root);

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            if(visited[it])
            {
                return false;
            }

            visited[it]=true;

            if(leftChild[it]!=-1)
            {
                q.push(leftChild[it]);
            }

            if(rightChild[it]!=-1)
            {
                q.push(rightChild[it]);
            }
        }

        return accumulate(visited.begin(), visited.end(), 0)==n;
    }
};