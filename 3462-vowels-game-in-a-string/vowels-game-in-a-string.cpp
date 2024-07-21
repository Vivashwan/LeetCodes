class Solution {
public:
    bool doesAliceWin(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        
        int vowelCount = 0;
        for (char c : s) {
            if (vowels.count(c)) 
            {
                vowelCount++;
            }
        }
        
        if(vowelCount==0)
        {
            return false;
        }
        
        return true;
    }
};