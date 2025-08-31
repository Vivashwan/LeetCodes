class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int, int>count;

        int mask=0;

        count[0]=1;

        long long res=0;

        for(auto it: word)
        {
            mask^=1<<(it-'a');

            res+=count[mask];

            for(int i=0; i<10; i++)
            {
                res+=count[mask^(1<<i)];
            }           

            count[mask]++;
        }

        return res;
    }
};