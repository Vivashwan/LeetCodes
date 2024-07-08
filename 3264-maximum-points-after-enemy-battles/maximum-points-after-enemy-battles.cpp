class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());

        if(currentEnergy<enemyEnergies[0])
        {
            return 0;
        }

        long long curr = currentEnergy;

        for(int i=enemyEnergies.size()-1; i>0; --i)
        {
            curr+=enemyEnergies[i];
        }

        return curr/enemyEnergies[0];
    }
};