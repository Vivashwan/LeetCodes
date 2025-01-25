class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sum=0, count=0, n=garbage.size(), m = n-1;

        unordered_map<char, int>last;

        for(int i=0; i<n; i++)
        {
            count+=garbage[i].size();

            for(auto it:garbage[i])
            {
                last[it]=sum;
            }

            if(i<m)
            {
                sum+=travel[i];
            }
        }

        return count+last['M']+last['P']+last['G'];
    }
};