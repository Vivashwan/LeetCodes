class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>>pq;

        for(int i=0; i<n; i++)
        {
            int pass = classes[i][0], total = classes[i][1];

            double ratio1 = (double)pass/(double)total;

            int newPass = classes[i][0]+1, newTotal = classes[i][1]+1;

            double ratio2 = (double)newPass/(double)newTotal;

            pq.push({ratio2-ratio1, i});
        }

        while(extraStudents)
        {
            auto it = pq.top();
            pq.pop();

            int index = it.second;

            classes[index][0]+=1;
            classes[index][1]+=1;

            int pass = classes[index][0], total = classes[index][1];

            double ratio1 = double(pass)/(double)total;

            int newPass = classes[index][0]+1, newTotal = classes[index][1]+1;

            double ratio2 = (double)newPass/(double)newTotal;

            pq.push({ratio2-ratio1, index});

            extraStudents--;
        }

        double sum=0;

        for(auto it:classes)
        {
            sum+=(double)it[0]/(double)it[1];
        }

        return sum/(double)n;
    }
};