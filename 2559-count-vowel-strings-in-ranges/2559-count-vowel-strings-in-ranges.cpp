class Solution {
private:
    bool isTrue(string& str)
    {
        char left = str[0], right = str[str.length()-1];

        bool leftTrue = false, rightTrue = false;

        if(left=='a' || left=='e' || left=='i' || left=='o' || left=='u')
        {
            leftTrue = true;
        }

        if(right=='a' || right=='e' || right=='i' || right=='o' || right=='u')
        {
            rightTrue = true;
        }

        return leftTrue && rightTrue;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int>res, prefix(n, 0);

        if(isTrue(words[0]))
        {
            prefix[0]=1;
        }

        for(int i=1; i<n; i++)
        {
            if(isTrue(words[i]))
            {
                prefix[i]=prefix[i-1]+1;
            }
            else prefix[i]=prefix[i-1];
        }

        for(auto it: queries)
        {
            int left = it[0], right = it[1];

            if(left==0)
            {
                res.push_back(prefix[right]);
            }
            else res.push_back(prefix[right]-prefix[left-1]);
        }

        return res;
    }
};