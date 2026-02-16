class Solution {
private:
    struct myCmp {
        bool operator()(pair<char, int>&a, pair<char, int>&b)
        {
            if(a.first==b.first)
            {
                return a.second<b.second;
            }

            return a.first>b.first;
        }
    };
public:
    string clearStars(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, myCmp>pq;
        int n=s.length();
        vector<bool>toBeRemoved(n, false);

        for(int i=0; i<n; i++)
        {
            if(s[i]=='*')
            {
                toBeRemoved[pq.top().second]=true;
                pq.pop();
            }
            else
            {
                pq.push({s[i], i});
            }
        }

        string str;

        for(int i=0; i<n; i++)
        {
            if(s[i]!='*' && toBeRemoved[i]==false)
            {
                str+=s[i];
            }
        }

        return str;
    }
};