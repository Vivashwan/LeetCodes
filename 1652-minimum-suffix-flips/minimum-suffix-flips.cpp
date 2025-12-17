class Solution {
public:
    int minFlips(string target) {
        int n=target.length();

        int count=0;

        char curr='0';

        for(int i=0; i<n; i++)
        {
            if(curr!=target[i])
            {
                curr=target[i];
                count++;
            }
        }

        return count;
    }
};