class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int>requirements;

        int count=0;

        for(auto it: answers)
        {
            if(requirements[it]==0)
            {
                requirements[it]=it;
                count+=it+1;
            }
            else
            {
                requirements[it]--;
            }
        }

        return count;
    }
};