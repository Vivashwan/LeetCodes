class Solution {
public:
    int m, n;
    vector<vector<int>>score;
    int ans=0;

    void backtrack(int studentIdx, vector<bool>& used, int currSum)
    {
        if(studentIdx==m)
        {
            ans=max(ans, currSum);
            return;
        }

        for(int mentor=0; mentor<m; mentor++)
        {
            if(!used[mentor])
            {
                used[mentor]=true;
                backtrack(studentIdx+1, used, currSum+score[studentIdx][mentor]);
                used[mentor]=false;
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        m=students.size();
        n=students[0].size();

        score.assign(m, vector<int>(m, 0));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<m; j++)
            {
                int cnt=0;

                for(int k=0; k<n; k++)
                {
                    if(students[i][k]==mentors[j][k])
                    { 
                        cnt++;
                    }
                }

                score[i][j]=cnt;
            }
        }

        vector<bool>used(m, false);

        backtrack(0, used, 0);
        
        return ans;
    }
};
