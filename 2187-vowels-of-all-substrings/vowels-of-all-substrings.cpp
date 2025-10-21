class Solution {
public:
    long long countVowels(string word) {
        long long total=0;
        int n=word.size();
        unordered_set<char>vowels={'a', 'e', 'i', 'o', 'u'};
        
        for(int i=0; i<n; i++) 
        {
            if(vowels.count(word[i])) 
            {
                total+=(long long)(i+1)*(n-i);
            }
        }
        
        return total;
    }
};