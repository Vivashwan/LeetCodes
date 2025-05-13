class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str=to_string(n);
        int marker=str.size(), size=str.size();

        for(int i=size-2; i>=0; i--)
        {
            if(str[i]>str[i+1])
            {
                str[i]--, marker=i+1;
            }
        }

        for(int i=marker; i<size; i++)
        {
            str[i]='9';
        }

        return stoi(str);
    }
};
