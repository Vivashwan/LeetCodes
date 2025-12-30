class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int>mp;
        
        for(auto it: tasks)
        {
            mp[it]++;
        }

        int rounds=0;

        for(auto &[task, freq]: mp) 
        {
            if(freq==1)
            { 
                return -1;
            }

            if(freq%3==0) 
            {
                rounds+=freq/3;
            } 
            else if(freq%3==1) 
            {
                rounds+=(freq-4)/3+2;
            } 
            else 
            {
                rounds+=freq/3+1;
            }
        }

        return rounds;
    }
};