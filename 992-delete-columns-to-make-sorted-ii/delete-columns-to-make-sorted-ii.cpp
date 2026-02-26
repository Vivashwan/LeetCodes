class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size(), m=strs[0].length();

        int count=0;
        vector<bool>resolved(n-1, false);

        for(int j=0; j<m; j++)
        {
            bool shouldBeDeleted=false;
            for(int i=0; i<n-1; i++)
            {
                if(!resolved[i] && strs[i][j]>strs[i+1][j])
                {
                    shouldBeDeleted=true;
                    break;
                }
            }

            if(shouldBeDeleted)
            {
                count++;
                continue;
            }

            for(int i=0; i<n-1; i++)
            {
                if(!resolved[i] && strs[i][j]<strs[i+1][j])
                {
                    resolved[i]=true;
                }
            }
        }

        return count;
    }
};