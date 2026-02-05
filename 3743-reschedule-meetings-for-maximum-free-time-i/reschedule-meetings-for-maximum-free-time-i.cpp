class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();

        vector<int>gaps;

        gaps.push_back(startTime[0]);

        for(int i=1; i<n; i++)
        {
            gaps.push_back(startTime[i]-endTime[i-1]);
        }

        gaps.push_back(eventTime-endTime[n-1]);

        int window=k+1;
        long long blocks=0;
        for(int i=0; i<window && gaps.size(); i++)
        {
            blocks+=gaps[i];
        }

        long long res=blocks;

        for(int i=window; i<gaps.size(); i++)
        {
            blocks-=gaps[i-window];
            blocks+=gaps[i];

            res=max(res, blocks);
        }

        return (int)res;
    }
};