class Solution {
public:
    int solve(string key, int k, char ch)
    {
        int i=0, j=0, count=0, ans=0;

        while(j<key.size())
        {
            if(key[j]!=ch)
            { 
                count++;
            }

            if(count<=k)
            { 
                ans=max(ans,j-i+1);
            }
            else
            {
                while(count>k)
                {
                    if(key[i]!=ch)
                    { 
                        count--;
                    }

                    i++;
                }
            }

            j++;
        }

        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(solve(answerKey, k, 'T'), solve(answerKey, k, 'F'));
    }
};