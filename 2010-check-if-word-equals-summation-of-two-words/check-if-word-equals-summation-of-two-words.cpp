class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int n=firstWord.size(), m=secondWord.size(), l=targetWord.size();

        int first=0, second=0, target=0;

        for(int i=0; i<n; i++)
        {    
            first=first*10 + (firstWord[i]-'a');
        }
        
        for(int i=0; i<m; i++)
        {    
            second=second*10 + (secondWord[i]-'a');
        }
        
        for(int i=0;i<l;i++)
        {    
            target=target*10 + (targetWord[i]-'a');
        }
    
        return first+second==target;
    }
};