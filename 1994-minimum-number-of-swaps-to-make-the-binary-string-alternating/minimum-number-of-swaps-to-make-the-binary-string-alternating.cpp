class Solution {
private:
    int canMake(string&s, char expectedChar, int n)
    {
        int count=0;

        for(int i=0; i<n; i++)
        {
            if(s[i]!=expectedChar)
            {
                count++;
            }

            expectedChar=(expectedChar=='0') ? '1':'0';
        }

        return count;
    }
public:
    int minSwaps(string s) {
        int n=s.length();

        int count1=0, count0=0;

        for(auto it: s)
        {
            if(it=='0')
            {
                count0++;
            }
            else count1++;
        }

        if(abs(count0-count1)>1)
        {
            return -1;
        }

        if(count0==count1)
        {
            return min(canMake(s, '0', n)/2, canMake(s, '1', n)/2);
        }

        if(count0<count1)
        {
            return canMake(s, '1', n)/2;
        }

        return canMake(s, '0', n)/2;
    }
};