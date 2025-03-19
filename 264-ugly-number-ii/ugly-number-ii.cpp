class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seen;
        
        minHeap.push(1);
        seen.insert(1);
        
        long ugly = 1;
        int factors[] = {2, 3, 5};
        
        for(int i=1; i<=n; i++) 
        {
            ugly = minHeap.top();
            minHeap.pop();
            
            for(int factor : factors) 
            {
                long nextUgly = ugly*factor;
                if(!seen.count(nextUgly)) 
                {
                    seen.insert(nextUgly);
                    minHeap.push(nextUgly);
                }
            }
        }
        
        return ugly;
    }   
};