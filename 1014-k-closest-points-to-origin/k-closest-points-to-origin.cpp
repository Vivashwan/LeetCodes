class Solution {
private:
    static bool myCmp(pair<int, int>& a, pair<int, int>& b) {
        double data1 = sqrt(pow(a.first - 0, 2) + pow(a.second - 0, 2));
        double data2 = sqrt(pow(b.first - 0, 2) + pow(b.second - 0, 2));

        return data1 < data2;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&myCmp)> pq(&myCmp);

        for(int i=0; i<n; i++)
        {
            auto it = points[i];

            pq.push({it[0], it[1]});
        }

        while(pq.size()>k)
        {
            pq.pop();
        }

        vector<vector<int>>res;

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            res.push_back({it.first, it.second});
        }   

        return res;
    }
};