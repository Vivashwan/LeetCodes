class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)
        {
            return true;
        }

        int left=0, right=s1.length();

        while(left<=right)
        {
            if(s1[left]==s2[left])
            {
                left++;
            }
            else if(s1[right]==s2[right])
            {
                right--;
            }
            else 
            {
                swap(s1[left], s1[right]);;

                if(s1==s2)
                {
                    return true;
                }
                else return false;
            }
        }

        return true;
    }
};