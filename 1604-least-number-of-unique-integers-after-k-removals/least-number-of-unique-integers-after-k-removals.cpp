class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;

        int n=arr.size();

        unordered_map<int, int>mp;

        for(auto it: arr)
        {
            mp[it]++;
        }

        for(auto it: mp)
        {
            pq.push(it.second);
        }

        while(!pq.empty() && k>=pq.top()) 
        {
            k-=pq.top();
            pq.pop();
        }

        return pq.size();
    }
};