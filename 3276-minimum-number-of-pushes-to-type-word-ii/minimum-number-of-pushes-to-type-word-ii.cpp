class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();

        vector<int>freq(26, 0);

        for(auto it: word)
        {
            freq[it-'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int count=0;

        for(int i=0; i<26; i++)
        {
            if(freq[i]==0)
            {
                break;
            }

            count+=((i/8)+1)*freq[i];
        }

        return count;
    }
};