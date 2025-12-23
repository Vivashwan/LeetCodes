class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n=word.length();
        unordered_map<char, int>mp;

        for(auto it: word)
        {
            mp[it]++;
        }

        vector<int>freq;

        for(auto it: mp)
        {
            freq.push_back(it.second);
        }

        sort(freq.begin(), freq.end());

        int count=INT_MAX;

        for(int i=0; i<freq.size(); i++)
        {
            int lowest=freq[i], dist=0;

            for(int j=0; j<freq.size(); j++)
            {
                if(freq[j]<lowest)
                {
                    dist+=freq[j];
                }
                else if(freq[j]>lowest+k)
                {
                    dist+=(freq[j]-(lowest+k));
                }
            }

            count=min(count, dist);
        }

        return count;
    }
};