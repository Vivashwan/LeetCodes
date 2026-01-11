class Solution {
public:
    int minDeletions(string s) {
        vector<int>freq(26, 0);

        for(auto it: s)
        {
            freq[it-'a']++;
        }

        set<int>st;

        int count=0;

        for(int i=0; i<26; i++)
        {
            while(freq[i]>0 && st.count(freq[i]))
            {
                freq[i]--;
                count++;
            }

            if(freq[i]>0)
            {
                st.insert(freq[i]);
            }
        }

        return count;
    }
};