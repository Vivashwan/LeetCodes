class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int sum=0;

        for(int i=0; i<k; i++)
        {
            sum+=cardPoints[i];
        }

        int res=sum;

        for(int i=k-1; i>=0; i--)
        {
            sum+=cardPoints[n-(k-i)];
            sum-=cardPoints[i];
            res=max(res, sum);
        }

        return res;
    }
};