class Solution {
public:
    char findKthBit(int n, int k) {
        unordered_map<int, string>mp;

        mp[1]="0";

        for(int i=2; i<=n; i++)
        {
            int j = mp[i-1].length()-1;

            string s1 = "";

            while(j>=0)
            {
                if(mp[i-1][j--]=='0')
                {
                    s1+='1';
                }
                else s1+='0';
            }

            mp[i]+=mp[i-1]+'1'+s1;
        }

        string res = mp[n];

        return res[k-1];
    }
};