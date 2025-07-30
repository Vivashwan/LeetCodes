class Solution {
public:
    int m, n;
    vector<vector<int>>score;
    int ans=0;

    void backtrack(int studentIdx, vector<bool>& used, int currSum)
    {
        if(studentIdx==n)
        {
            ans=max(ans, currSum);
            return;
        }

        for(int mentor=0; mentor<n; mentor++)
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
        n=students.size();
        m=students[0].size();

        score.assign(n, vector<int>(n, 0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                int cnt=0;

                for(int k=0; k<m; k++)
                {
                    if(students[i][k]==mentors[j][k])
                    { 
                        cnt++;
                    }
                }

                score[i][j]=cnt;
            }
        }

        vector<bool>used(n, false);

        backtrack(0, used, 0);

        return ans;
    }
};
