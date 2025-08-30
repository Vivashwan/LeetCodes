class Solution {
public:
    bool isAnagram(string str1, string str2) {

        if(str1.length()!=str2.length())
        {
            return false;
        }

        vector<int>count(256, 0);

        for (int i=0; i<str1.length(); i++)
        {
            count[str1[i]]++;
            count[str2[i]]--;
        }

        for(int i=0; i<256; i++)
        {
            if(count[i]!=0)
            {
                return false;
            }
        }

        return true;
    }
};