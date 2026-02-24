class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();

        priority_queue<double>pq;

        double sum=0;

        for(auto it: nums)
        {
            sum+=it;

            pq.push(it);
        }

        double target=sum/2.0;

        int count=0;

        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();

            double half=it/2.0;
            sum-=half;

            count++;

            if((double)sum<=target)
            {   
                break;
            }

            pq.push(it/2);
        }

        return count;
    }
};