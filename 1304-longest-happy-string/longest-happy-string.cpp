class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;

        if(a>0)
        {
            pq.push({a, 'a'});
        }

        if(b>0)
        {
            pq.push({b, 'b'});
        }

        if(c>0)
        {
            pq.push({c, 'c'});
        }

        string res;

        while(!pq.empty())
        {
            auto [occ1, ch1]=pq.top();
            pq.pop();

            int len=res.length();

            if(len>=2 && res[len-1]==ch1 && res[len-2]==ch1)
            {
                if(pq.empty())
                {
                    break;
                }

                auto [occ2, ch2]=pq.top();
                pq.pop();

                res+=ch2;
                occ2--;

                if(occ2>0)
                {
                    pq.push({occ2, ch2});
                }

                pq.push({occ1, ch1});
            }
            else 
            {
                res+=ch1;
                occ1--;

                if(occ1>0)
                { 
                    pq.push({occ1, ch1});
                }
            }
        }

        return res;
    }
};