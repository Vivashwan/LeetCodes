class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size()+1;

        int total=0;

        for(int i=1; i<=n; i++)
        {
            total^=i;
        }

        int oddXor=0;

        for(int i=1; i<encoded.size(); i+=2)
        {
            oddXor^=encoded[i];
        }

        vector<int>perm(n);
        perm[0]=total^oddXor;

        for(int i=1; i<n; i++)
        {
            perm[i]=perm[i-1]^encoded[i-1];
        }

        return perm;
    }
};