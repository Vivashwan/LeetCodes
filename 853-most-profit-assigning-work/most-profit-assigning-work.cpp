class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=profit.size();

        unordered_map<int, vector<int>>mp;

        for(auto workerStrength: worker)
        {
            int val=0;

            for(int i=0; i<n; i++)
            {
                if(workerStrength>=difficulty[i])
                {
                    val=max(val, profit[i]);
                }
            }

            mp[workerStrength].push_back(val);
        }

        int total=0;

        for(auto it: mp)
        {
            total+=accumulate(it.second.begin(), it.second.end(), 0);
        }

        return total;
    }
};