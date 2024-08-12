class Solution {
public:
    string getSmallestString(int n, int k) {
        string str(n, 'a');
        k-=n;

        for(int i=n-1; i>=0 && k>0; --i)
        {
            int add = min(k, 25);

            str[i]+=add;

            k-=add;
        }

        return str;
    }
};