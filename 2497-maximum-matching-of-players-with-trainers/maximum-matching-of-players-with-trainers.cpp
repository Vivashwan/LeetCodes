class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n=players.size(), m=trainers.size();

        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());

        int p=0, count=0;
        
        for(int i=0; i<m; i++)
        {
            while(p<n && players[p]>trainers[i])
            {
                p++;
            }

            if(p==n)
            {
                break;
            }

            count++;
            p+=1;
        }

        return count;
    }
};