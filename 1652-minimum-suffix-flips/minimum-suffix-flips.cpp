class Solution {
public:
    int minFlips(string target) {
        int n = target.size();
        int flips = 0;
        char current = '0';

        for (int i = 0; i < n; i++) 
        {
            if (target[i] != current) 
            {
                flips++;
                current = target[i]; 
            }
        }
        
        return flips;
    }
};
