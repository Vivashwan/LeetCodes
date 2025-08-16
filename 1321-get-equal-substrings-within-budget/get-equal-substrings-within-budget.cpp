class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.length(), left=0, sum=0, maxLen=0;

        for(int right=0; right<n; right++)
        {
            sum+=abs((s[right]-'a')-(t[right]-'a'));

            if(sum<=maxCost)
            {
                maxLen=max(maxLen, right-left+1);
            }
            else
            {
                while(sum>maxCost)
                {
                    sum-=abs((s[left]-'a')-(t[left]-'a'));
                    left++;
                }
            }
        }

        return maxLen;
    }
};