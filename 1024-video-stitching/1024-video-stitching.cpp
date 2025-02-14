class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        int n=clips.size();

        sort(clips.begin(), clips.end());

        int end=0, count=0, i=0;
 
        while(end<time) 
        {
            int newEnd=end;

            while(i<n && clips[i][0]<=end) 
            {
                newEnd=max(newEnd, clips[i][1]);
                i++;
            }

            if(newEnd==end) 
            {
                return -1;
            }

            end=newEnd;
            count++;
        }

        return count;
    }
};