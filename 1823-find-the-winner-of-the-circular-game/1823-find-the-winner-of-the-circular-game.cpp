class Solution {
public:
    int findTheWinner(int n, int k) {
        int winner=0;

        for(int person=2; person<=n; person++)
        {
            winner=(winner+k)%person;
        }

        return winner+1;
    }
};