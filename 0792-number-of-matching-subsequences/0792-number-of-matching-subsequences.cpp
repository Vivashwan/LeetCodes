class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>>mp;

        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]].push_back(i);
        }

        int count=0;

        for(auto v: words)
        {
            int prevIndex=-1;
            bool isSubSeq=true;

            for(auto u: v)
            {
                if(mp.find(u)==mp.end())
                {
                    isSubSeq=false;
                    break;
                }

                auto &indices=mp[u];

                auto it=upper_bound(indices.begin(), indices.end(), prevIndex);

                if(it==indices.end())
                {
                    isSubSeq=false;
                    break;
                }

                prevIndex = *it;
            }

            if(isSubSeq)
            {
                count++;
            }
        }

        return count;
    }
};