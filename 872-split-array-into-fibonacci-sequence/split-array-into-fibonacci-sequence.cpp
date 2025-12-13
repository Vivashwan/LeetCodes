class Solution {
private:
    vector<int>res;
    bool dfs(string& s, int n, int ind)
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

            if(num>INT_MAX)
            { 
                break;
            }

            int size=res.size();

            if(size>=2)
            {
                long long sum=(long long)res[size-1]+res[size-2];

                if(num<sum)
                {
                    continue;
                }

                if(num>sum)
                {
                    break;
                }
            }

            res.push_back((int)num);

            if(dfs(s, n, i+1))
            {
                return true;
            }

            res.pop_back();
        }

        return false;
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        int n=num.length();

        dfs(num, n, 0);

        return res;
    }
};