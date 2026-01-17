class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int maxim=0;
        int n=tokens.size();

        sort(tokens.begin(), tokens.end());

        int low=0, high=n-1, score=0;

        while(low<=high)
        {
            if(power>=tokens[low])
            {
                power-=tokens[low];
                score++;
                low++;
            }
            else if(score>0)
            {
                power+=tokens[high];
                score--;
                high--;
            }
            else low++;

            maxim=max(maxim, score);
        }

        return maxim;
    }
};