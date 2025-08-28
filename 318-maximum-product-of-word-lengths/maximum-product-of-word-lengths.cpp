class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        int res=0;

        for(int i=0; i<n; i++) 
        {
            unordered_set<char>s(words[i].begin(), words[i].end());

            for(int j=i+1; j<n; j++) 
            {
                bool share=false;

                for(char c: words[j]) 
                {
                    if(s.count(c)) 
                    {
                        share=true;
                        break;
                    }
                }

                if(!share) 
                {
                    res=max(res, (int)words[i].size()*(int)words[j].size());
                }
            }
        }
        
        return res;
    }
};
