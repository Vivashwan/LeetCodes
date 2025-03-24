class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int coin5=0, coin10=0;

        for(int i=0; i<n; i++)
        {
            if(bills[i]==5)
            {
                coin5++;
            }
            else if(bills[i]==10)
            {
                if(coin5>=1)
                {
                    coin10++;
                    coin5--;
                }
                else return false;
            }
            else if(bills[i]==20)
            {
                if((coin10>=1 && coin5>=1))
                {
                    coin5--, coin10--;
                }
                else if((coin5>=3))
                {
                    coin5-=3;
                }
                else return false;
            }
        }

        return true;
    }
};