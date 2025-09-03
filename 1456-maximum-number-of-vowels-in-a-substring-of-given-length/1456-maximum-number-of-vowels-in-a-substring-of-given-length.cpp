class Solution {
private:
    bool isVowel(char ch)
    {
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        {
            return true;
        }

        return false;
    }
public:
    int maxVowels(string s, int k) {
        int n=s.length(), count=0;

        for(int i=0; i<k; i++)
        {
            if(isVowel(s[i]))
            {
                count++;
            }
        }

        int res=count;

        for(int i=k; i<n; i++)
        {
            if(isVowel(s[i-k]))
            {
                count--;
            }

            if(isVowel(s[i]))
            {
                count++;
            }

            res=max(res, count);
        }

        return res;
    }
};