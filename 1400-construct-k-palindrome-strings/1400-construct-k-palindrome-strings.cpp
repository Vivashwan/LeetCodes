class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.length();

        if(k>n)
        {
            return 0;
        }

        if(k==n)
        {
            return 1;
        }

        vector<int>v(26, 0);

        for(int i=0; i<n; i++)
        {
            v[s[i]-'a']++;
        }

        int count=0;

        for(int i=0; i<26; i++)
        {
            if(v[i]%2==1)
            {
                count++;
            }
        }

        return count<=k;
    }
};