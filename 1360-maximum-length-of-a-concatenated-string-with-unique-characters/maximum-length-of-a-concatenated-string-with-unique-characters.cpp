class Solution {
private:
    int dfs(vector<int>& masks, int index, int currMask) 
    {
        if(index==masks.size()) 
        {    
            return __builtin_popcount(currMask);
        }
        
        int res=dfs(masks, index+1, currMask);
        
        if((currMask & masks[index])==0) 
        {
            res=max(res, dfs(masks, index+1, currMask | masks[index]));
        }
        
        return res;
    }
    
public:
    int maxLength(vector<string>& arr) {
        vector<int>masks;

        for(auto &s: arr) 
        {
            int mask=0;
            bool valid=true;

            for(char c: s) 
            {
                int bit=c-'a';

                if(mask & (1<<bit)) 
                {
                    valid=false;
                    break;
                }

                mask |= (1<<bit);
            }

            if(valid)
            { 
                masks.push_back(mask);
            }
        }
        
        return dfs(masks, 0, 0);
    }
};
