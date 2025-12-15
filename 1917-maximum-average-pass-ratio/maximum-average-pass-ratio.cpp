class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, pair<int, int>>>pq;

        for(auto it: classes)
        {
            int passing=it[0], total=it[1];

            double gain=(double)(passing+1)/(total+1)-(double)passing/total;

            pq.push({gain, {passing, total}});
        }

        while(extraStudents--)
        {
            auto it=pq.top();
            pq.pop();

            int passing=it.second.first, total=it.second.second;

            passing++, total++;

            double newGain=(double)(passing+1)/(total+1)-(double)passing/total;

            pq.push({newGain, {passing, total}});
        }

        double sum=0;

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();

            sum+=(double)it.second.first/it.second.second;
        }

        return sum/classes.size();
    }
};