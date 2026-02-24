class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int deletions=0;
        bool evenIndex=true;
        int prev;

        for(auto it: nums)
        {
            if(evenIndex)
            {
                prev=it;
                evenIndex=false;
            }
            else
            {
                if(it==prev)
                {
                    deletions++;
                }
                else
                {
                    evenIndex=true;
                }
            }
        }

        if(!evenIndex) 
        { 
            deletions++; 
        }

        return deletions;
    }
};