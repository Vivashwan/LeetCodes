class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int reach=n/2, count=0;

        vector<int>freq(100001, 0);

        for(auto it: arr)
        {
            freq[it]++;
        }

        priority_queue<int, vector<int>>pq;

        for(auto it: freq)
        {
            if(it==0)
            {
                continue;
            }

            pq.push(it);
        }

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();

            reach-=it;
            count++;

            if(reach<=0)
            {
                break;
            }
        }

        return count;
    }
};