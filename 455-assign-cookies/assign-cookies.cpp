class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();

        if(m==0)
        {
            return 0;
        }

        sort(g.begin(), g.end()), sort(s.begin(), s.end());

        int i=0, j=0, count=0;

        while(i<n && j<m)
        {
            if(s[j]>=g[i])
            {
                count++;
                i++, j++;
            }
            else j++;
        }

        return count;
    }
};