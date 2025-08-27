class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n=s.size();

        unordered_map<string, int>freq;
        unordered_map<char, int>charCount;

        int distinct=0, left=0;

        for(int right=0; right<n; right++)
        {
            if(charCount[s[right]]==0)
            {
                distinct++;
            }

            charCount[s[right]]++;

            if(right-left+1>minSize)
            {
                charCount[s[left]]--;

                if(charCount[s[left]]==0)
                {
                    distinct--;
                }

                left++;
            }

            if(right-left+1==minSize && distinct<=maxLetters)
            {
                freq[s.substr(left, minSize)]++;
            }
        }

        int count=0;

        for(auto it: freq)
        {
            count=max(count, it.second);
        }

        return count;
    }
};