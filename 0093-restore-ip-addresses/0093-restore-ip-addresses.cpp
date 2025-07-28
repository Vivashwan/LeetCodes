class Solution {
private:
    bool isSafe(string &segment)
    {
        if(segment.size()>1 && segment[0]=='0')
        {
            return false;
        }

        int val=stoi(segment);
        return 0<=val && val<=255;
    }
    void func(int start, int totalSegments, int n, string current, string&s, vector<string>&res)
    {
        if(totalSegments==4 && start==n)
        {
            res.push_back(current);
            return;
        }

        for(int i=1; i<=3 && start+i<=n; i++)
        {
            string segment=s.substr(start, i);

            if(isSafe(segment))
            {
                string updatedSegment=(totalSegments==0)?segment : "."+segment;

                func(start+i, totalSegments+1, n, current+updatedSegment, s, res);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int n=s.length();

        if(n<4 || n>12)
        {
            return {};
        }

        vector<string>res;

        func(0, 0, n, "", s, res);

        return res;
    }
};