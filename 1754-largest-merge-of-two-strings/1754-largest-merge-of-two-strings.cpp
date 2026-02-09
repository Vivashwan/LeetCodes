class Solution {
public:
    string largestMerge(string word1, string word2) {
        int i=0, j=0;
        int n=word1.size(), m=word2.size();
        string ans;

        while(i<n && j<m) 
        {
            if(word1.substr(i) > word2.substr(j)) 
            {
                ans+=word1[i++];
            } 
            else 
            {
                ans+=word2[j++];
            }
        }

        if(i<n)
        { 
            ans+=word1.substr(i);
        }

        if(j<m) 
        {
            ans+=word2.substr(j);
        }

        return ans;
    }
};
