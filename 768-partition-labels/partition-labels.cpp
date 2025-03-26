class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();

        vector<int>endPos(26, 0), res;

        for(int i=0; i<n; i++)
        {
            endPos[s[i]-'a']=i;
        }

        int start=0, end=0;

        for(int i=0; i<n; i++)
        {
            end=max(end, endPos[s[i]-'a']);

            if(i==end)
            {
                res.push_back(end-start+1);
                start=i+1;
            }
        }

        return res;
    }
};