class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(), m=needle.size();

        if(m>n)
        {
            return -1;
        }

        int needleIndex=0;

        for(int i=0; i<n; i++)
        {
            if(haystack[i]==needle[needleIndex])
            {
                needleIndex++;
            }
            else
            {
                i=i-needleIndex;
                needleIndex=0;
            }

            if(needleIndex==m)
            {
                return i-needleIndex+1;
            }
        }

        return -1;
    }
};