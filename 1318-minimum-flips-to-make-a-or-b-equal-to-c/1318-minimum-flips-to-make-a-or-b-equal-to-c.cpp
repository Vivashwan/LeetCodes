class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;

        for(int i=0; i<32; i++)
        {
            if(c>>i & 1)
            {
                if((a>>i & 1) ||(b>>i & 1))
                {
                    continue;
                }
                else count++;
            }
            else
            {
                if((a>>i & 1) && (b>>i & 1))
                {
                    count+=2;
                }
                else if((a>>i & 1 )|| (b>>i & 1))
                {
                    count++;
                }
                else continue;
            }
        }

        return count;
    }
};