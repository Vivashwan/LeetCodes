class Solution {
public:
    int maximumSwap(int num) {
        string str=to_string(num);
        int n=str.length();

        unordered_map<char, int>mp;

        for(int i=0; i<n; i++)
        {
            mp[str[i]]=i;
        }

        for(int i=0; i<n; i++)
        {
            for(char val='9'; val>str[i]; val--)
            {
                if(mp[val]>i)
                {
                    swap(str[mp[val]], str[i]);
                    return stoi(str);
                }
            }
        }

        return stoi(str);
    }
};