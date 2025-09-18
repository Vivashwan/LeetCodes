class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;

        for(int bit=0; bit<32; bit++)
        {
            count += ((x >> bit) & 1) ^ ((y >> bit) & 1);
        }

        return count;
    }
};