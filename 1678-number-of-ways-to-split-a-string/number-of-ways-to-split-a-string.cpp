class Solution {
public:
    int numWays(string s) {
       long ones = 0, n = s.size(), mod = 1e9+7;

        for(int i=0; i<n; i++)
        {
                if(s[i]=='1')
                {
                    ones++;
                }
        }

        if(ones%3!=0)
        {
            return 0;
        }

        if(ones==0)
        {
            return (int)(((n-1)*(n-2)/2)%mod);
        }

        long firstOneThird = ones/3, secondOneThird = 2*firstOneThird;
        ones = 0;

        long firstWay = 0, secondWay = 0;

        for(int i=0; i<n; ++i)
        {
            if(s[i]=='1')
            {
                ones++;
            }

            if(ones==firstOneThird)
            {
                firstWay++;
            }

            if(ones == secondOneThird)
            {
                secondWay++;
            }
        }

        return (firstWay*secondWay)%mod;
    }
};