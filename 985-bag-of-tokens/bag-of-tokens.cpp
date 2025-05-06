class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin(), tokens.end());

        int start=0, end=n-1;

        int score=0, maxim=0;

        while(start<=end)
        {
            if(tokens[start]<=power)
            {
                power-=tokens[start];
                start++, score++;

                maxim = max(maxim, score);
            }
            else if(score>0)
            {
                power+=tokens[end];
                end--, score--;

            }
            else break;
        }


        return maxim;
    }
};