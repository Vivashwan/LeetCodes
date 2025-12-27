class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int n=s1.length(), xyPairs=0, yxPairs=0;

        for(int i=0; i<n; i++)
        {
            if(s1[i]!=s2[i])
            {
                if(s1[i]=='x')
                {
                    xyPairs++;
                }
                else if(s1[i]=='y')
                {
                    yxPairs++;
                }
            }
        }

        if((xyPairs+yxPairs)%2)
        {
            return -1;
        }

        int count=(xyPairs+yxPairs)/2;

        if(xyPairs%2 || yxPairs%2)
        {
            count++;
        }
        
        return count;
    }
};