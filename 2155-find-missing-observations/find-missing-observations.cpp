class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();

        long sum = accumulate(begin(rolls), end(rolls), 0), total = (n+m)*mean;

        long missing = total-sum;

        if(missing<n || missing>n*6)
        {
            return {};
        }

        vector<int>res(n, 1);

        missing -= n;

        for(int i=0; i<n; i++)
        {
            res[i]+=min(long(5), missing);

            missing -= min(long(5), missing);

            if(missing<=0)
            {
                break;
            }
        }

        return res;
    }   
};