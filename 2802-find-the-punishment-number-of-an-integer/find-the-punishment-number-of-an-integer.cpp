class Solution {
private:
    bool func(string str, int target, int ind, int sum)
    {
        if(ind==str.length())
        {
            return sum==target;
        }

        int num=0;

        for(int j=ind; j<str.length(); j++)
        {
            num=num*10+(str[j]-'0');

            if(sum+num>target)
            {
                break;
            }

            if(func(str, target, j+1, sum+num))
            {
                return true;
            }
        }

        return false;
    }
public:
    int punishmentNumber(int n) {
        int count=0;

        for(int i=1; i<=n; i++)
        {
            string s=to_string(i*i);
            if(func(s, i, 0, 0))
            {
                count+=i*i;
            }
        }
        
        return count;
    }
};