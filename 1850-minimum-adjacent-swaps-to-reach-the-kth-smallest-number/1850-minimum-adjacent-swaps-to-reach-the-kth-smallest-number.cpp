class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n = num.length();

        string temp = num;

        while(k--)
        {
            next_permutation(temp.begin(), temp.end());
        }

        int res = 0;

        for(int i=0; i<n; i++)
        {
            int j=i+1;

            while(num[i]!=temp[i])
            {
                res++;
                swap(temp[i], temp[j]);
                j++;
            }
        }

        return res;
    }
};