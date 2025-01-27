class Solution {
public:
    int bestClosingTime(string customers) {
        int maxi=0, penalty=0, res=-1, n=customers.size();

        for(int i=0; i<n; i++)
        {
            penalty+=(customers[i]=='Y') ? 1:-1;

            if(penalty>maxi)
            {
                maxi=penalty;
                res=i;
            }
        }

        return res+1;
    }
};