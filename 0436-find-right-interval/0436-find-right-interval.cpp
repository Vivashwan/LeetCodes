class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int, int>>starts;
        
        for(int i=0; i<n; i++) 
        {
            starts.push_back({intervals[i][0], i});
        }
        
        sort(starts.begin(), starts.end());
        
        vector<int>result(n, -1);
        
        for(int i=0; i<n; i++)
        {
            int end=intervals[i][1];
            
            int low=0, high=n-1;
            int idx=-1;

            while(low<=high)
            {
                int mid=(low+high)/2;

                if(starts[mid].first>=end)
                {
                    idx=starts[mid].second;
                    high=mid-1;
                } 
                else
                {
                    low=mid+1;
                }
            }
            
            result[i]=idx;
        }
        
        return result;
    }
};