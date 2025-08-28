class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int>mask(n), len(n);

        for(int i=0; i<n; i++)
        {
            int m=0;

            for(char c:words[i]) 
            {
                m|=(1<<(c-'a'));
            }

            mask[i]=m;
            len[i]=words[i].size();
        }

        int res=0;

        for(int i=0; i<n; i++) 
        {
            for(int j=i+1; j<n; j++) 
            {
                if((mask[i] & mask[j])==0) 
                {
                    res=max(res, len[i]*len[j]);
                }
            }
        }
        
        return res;
    }
};
