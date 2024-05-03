class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n = s1.length();

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool flag1=true, flag2=true;

        for(int i=0; i<n; i++)
        {
            if(s1[i]>=s2[i])
            {
                continue;
            }

            flag1 = false;
        }

        for(int i=0; i<n; i++)
        {
            if(s2[i]>=s1[i])
            {
                continue;
            }

            flag2 = false;
        }

        return flag1 || flag2;
    }
};