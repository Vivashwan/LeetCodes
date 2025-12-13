class Solution {
private:
    bool func(string& s, int n, vector<long long>&res, int ind)
    {
        if(ind==n) 
        {
            return res.size()>=3;
        }

        long long num=0;

        for(int i=ind; i<n; i++)
        {
            if(i>ind && s[ind]=='0')
            {
                break;
            }

            num=num*10+(s[i]-'0');

            if(num>LLONG_MAX/10)
            { 
                break;
            }

            int size=res.size();

            if(size>=2)
            {
                long long sum=res[size-1]+res[size-2];

                if(num<sum)
                {
                    continue;
                }

                if(num>sum)
                {
                    break;
                }
            }

            res.push_back(num);

            if(func(s, n, res, i+1))
            {
                return true;
            }

            res.pop_back();
        }

        return false;
    }
public:
    bool isAdditiveNumber(string num) {
        int n=num.length();

        vector<long long>res;

        return func(num, n, res, 0);
    }
};