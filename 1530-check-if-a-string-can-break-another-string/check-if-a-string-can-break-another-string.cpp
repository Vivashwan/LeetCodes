class Solution {
private:
    bool func(string s1, string s2)
    {
        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i]<s2[i])
            {
                return false;
            }
        }

        return true;
    }
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return func(s1, s2) || func(s2, s1);
    }
};