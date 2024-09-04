class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();

        int X = 0;

        for(int i=1; i<=n+1; i++)
        {
            X^=i;
        }

        for(int i=1; i<n; i+=2)
        {
            X^=encoded[i];
        }

        vector<int>res;

        res.push_back(X);

        for(int i=0; i<n; i++)
        {
            X^=encoded[i];
            res.push_back(X);
        }


        return res;
    }
};