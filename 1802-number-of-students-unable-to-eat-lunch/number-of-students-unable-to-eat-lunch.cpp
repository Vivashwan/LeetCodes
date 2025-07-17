class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int>count(2, 0);

        for(auto it: students)
        {
            count[it]++;
        }   

        int remaining=sandwiches.size();

        for(int i=0; i<sandwiches.size(); i++)
        {
            if(count[sandwiches[i]]==0)
            {
                break;
            }

            if(remaining==0)
            {
                break;
            }

            count[sandwiches[i]]--;
            remaining--;
        }

        return remaining;
    }
};