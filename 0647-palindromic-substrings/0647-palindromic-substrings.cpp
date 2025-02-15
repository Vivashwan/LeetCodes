class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();

        int count=0;

        for(int i=0; i<n; i++)
        {
            for(int j=i; j>=0; j--)
            {
                int left=j, right=i, flag=1;

                while(left<=right)
                {
                    if(s[left]!=s[right])
                    {
                        flag=0;
                        break;
                    }

                    left++, right--;
                }

                if(flag)
                {
                    count++;
                }
            }
        }

        return count;
    }
};