class Solution {
private:
    bool func(vector<int>&matchsticks, vector<int>&sides, int target, int ind, int n)
    {
        if(ind==n)
        {
            return sides[0]==target && sides[1]==target && sides[2]==target && sides[3]==target;
        }

        for(int i=0; i<4; i++)
        {
            if(sides[i]+matchsticks[ind]>target)
            {
                continue;
            }

            sides[i]+=matchsticks[ind];
            if(func(matchsticks, sides, target, ind+1, n))
            {
                return true;
            }
            sides[i]-=matchsticks[ind];

            if(sides[i]==0)
            {
                break;
            }
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int n=matchsticks.size();

        int sum=accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if(sum%4!=0)
        {
            return false;
        }

        int side=sum/4;

        sort(matchsticks.rbegin(), matchsticks.rend());

        if(matchsticks[0]>side)
        {
            return false;
        }

        vector<int>sides(4, 0);

        return func(matchsticks, sides, side, 0, n);
    }
};