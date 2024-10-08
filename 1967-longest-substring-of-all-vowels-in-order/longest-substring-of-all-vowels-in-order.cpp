class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.length();

        if(n<5)
        {
            return 0;
        }

        int maxim = 0;

        string lookUp = "aeiou";
        
        int m = lookUp.length();

        for(int i=0; i<n; i++)
        {
            int k = i;

            if(word[i]=='a')
            {
                int vowelIndex = 0;  

                while(k<n && vowelIndex<lookUp.size()) 
                {
                    if(word[k] == lookUp[vowelIndex]) 
                    {
                        while(k < n && word[k] == lookUp[vowelIndex]) 
                        {
                            k++;
                        }

                        vowelIndex++; 
                    } 
                    else 
                    {
                        break; 
                    }
                }

                
                if(vowelIndex==lookUp.size()) 
                {
                    maxim = max(maxim, k - i);
                }

                i = k - 1;
            }
        }

        return maxim;
    }
};