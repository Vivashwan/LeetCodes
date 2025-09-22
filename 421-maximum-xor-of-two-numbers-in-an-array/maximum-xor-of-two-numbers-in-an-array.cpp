class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxXOR=0, mask=0;
        
        for(int bit=31; bit>=0; bit--)
        {
            mask|=(1<<bit);

            unordered_set<int>prefixes;

            for(auto it: nums)
            {  
                prefixes.insert(it & mask);
            }

            int candidate=maxXOR|(1<<bit);

            for(auto it: prefixes)
            {
                if(prefixes.count(it^candidate))
                {
                    maxXOR=candidate;
                    break;
                }
            }
        }

        return maxXOR;
    }
};