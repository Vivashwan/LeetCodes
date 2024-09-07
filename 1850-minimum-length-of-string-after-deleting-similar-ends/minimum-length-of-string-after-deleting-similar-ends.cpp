class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();

        int low = 0, high = n-1;

        while(low<high)
        {
            if(s[low]!=s[high])
            {
                break;
            }

            char ch1 = s[low], ch2 = s[high];

            while(low<=high && ch1==s[low])
            {
                low++;
            }

            while(low<=high && ch2==s[high])
            {
                high--;
            }
        }

        return high-low+1;
    }
};