class Solution {
public:
    int hammingWeight(int n) {
        int count=0;

        for(int bit=0; bit<32; bit++)
        {
            count+=(n>>bit)&1;
        }   

        return count;
    }
};