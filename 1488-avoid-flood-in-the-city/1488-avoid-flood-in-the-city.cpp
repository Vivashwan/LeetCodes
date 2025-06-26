class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();

        unordered_map<int, int>lakeReceivedRainOnDayi;

        set<int>dryDays;

        vector<int>res(n, 1);

        for(int i=0; i<n; i++)
        {
            if(rains[i]==0)
            {
                dryDays.insert(i);
                res[i]=1;
            }
            else
            {
                int lake=rains[i];
                res[i]=-1;

                if(lakeReceivedRainOnDayi.find(lake)!=lakeReceivedRainOnDayi.end())
                {
                    int lakeRainedOnDay=lakeReceivedRainOnDayi[lake];

                    auto dryDayAfterPrevDryDay=dryDays.upper_bound(lakeRainedOnDay);

                    if(dryDayAfterPrevDryDay==dryDays.end())
                    {
                        return {};
                    }

                    res[*dryDayAfterPrevDryDay]=lake;
                    dryDays.erase(dryDayAfterPrevDryDay);
                }
            }

            lakeReceivedRainOnDayi[rains[i]]=i;
        }

        return res;
    }
};