class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();

        vector<vector<int>>res;

        vector<bool>visited(n, false);

        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                vector<int>temp;

                for(int j=i; j<n; j++)
                {
                    if(!visited[j] && groupSizes[i]==groupSizes[j])
                    {
                        temp.push_back(j);

                        visited[j]=true;
                    }

                    if(temp.size()==groupSizes[i])
                    {
                        break;
                    }
                }

                res.push_back(temp);
            }

        }

        return res;
    }
};