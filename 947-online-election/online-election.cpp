class TopVotedCandidate {
private:
    vector<int>times, leader;
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times=times;

        int currentLeader=-1, maxVotes=0;
        unordered_map<int, int>mp;

        leader.resize(times.size());

        for(int i=0; i<times.size(); i++)
        {
            mp[persons[i]]++;

            if(mp[persons[i]]>=maxVotes)
            {
                maxVotes=mp[persons[i]];
                currentLeader=persons[i];
            }

            leader[i]=currentLeader;
        }
    }
    
    int q(int t) {
        int left=0, right=times.size()-1;

        int ans=-1;

        while(left<=right)
        {
            int mid=(left+right)/2;

            if(times[mid]<=t)
            {
                ans=mid, left=mid+1;
            } 
            else right=mid-1;
        }

        return leader[ans];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */