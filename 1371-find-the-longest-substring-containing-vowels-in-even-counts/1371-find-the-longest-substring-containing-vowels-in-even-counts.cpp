class Solution {
private:
    bool isVowel(char ch) 
    {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();

        int res = 0, curr = 0;

        unordered_map<char, int>vowelPos = {{'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4}};

        unordered_map<int, int>lastOcc;

        lastOcc[0]=-1;

        for(int i=0; i<n; i++)
        {
            if(isVowel(s[i]))
            {
                curr^=(1<<vowelPos[s[i]]);
            }

            if(lastOcc.find(curr)!=lastOcc.end())
            {
                res = max(res, i-lastOcc[curr]);
            }
            else lastOcc[curr]=i;
        }

        return res;
    }
};