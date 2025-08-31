class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length(), m = word2.length();

        if(n != m) {
            return false;
        }

        unordered_map<char, int> mp1, mp2;

        for(int i = 0; i < n; i++) 
        {
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        unordered_set<char> set1, set2;

        for (auto &p : mp1) 
        {
            set1.insert(p.first);
        }
        for (auto &p : mp2) 
        {
            set2.insert(p.first);
        }

        if (set1 != set2) 
        {
            return false;
        }

        vector<int> freq1, freq2;
        for (auto &p : mp1) 
        {
            freq1.push_back(p.second);
        }

        for (auto &p : mp2) 
        {
            freq2.push_back(p.second);
        }

        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};