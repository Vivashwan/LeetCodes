class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;

        for(auto c:chalk) 
        {
            totalChalk+=c;
        }

        k%=totalChalk;

        for(int i=0; i<chalk.size(); i++) 
        {
            if(k<chalk[i]) 
            {
                return i;
            }

            k-=chalk[i];
        }

        return -1;
    }
};