class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int curr=0, maxim = 0;

        vector<int>store(5, 0);

        for(auto ch: croakOfFrogs)
        {
            if(ch=='c')
            {
                curr++;
                store[0]++;
                maxim = max(maxim, curr);
            }
            else
            {
                if(ch=='r')
                {
                    if(store[0]<=store[1])
                    {
                        return -1;
                    }

                    store[1]++;
                }
                else if(ch=='o')
                {
                    if(store[1]<=store[2])
                    {
                        return -1;
                    }

                    store[2]++;
                }
                else if(ch=='a')
                {
                    if(store[2]<=store[3])
                    {
                        return -1;
                    }

                    store[3]++;
                }
                else if(ch=='k')
                {
                    if(store[3]<=store[4])
                    {
                        return -1;
                    }

                    store[4]++;

                    curr--;
                }
            }
        } 

        int total=store[0];

        for(auto it: store)
        {
            if(it!=total)
            {
                return -1;
            }
        } 

        return maxim;
    }
};