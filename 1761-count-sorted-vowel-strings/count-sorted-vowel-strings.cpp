class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>vowels(5, 1);

        for(int i=0; i<n; i++)
        {
            for(int j=4; j>0; j--)
            {
                vowels[j-1] += vowels[j];
            }
        }

        return vowels[0];
    }
};