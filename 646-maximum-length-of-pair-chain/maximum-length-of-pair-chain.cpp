class Solution {
private:
    static bool myCmp(vector<int>&a, vector<int>&b) 
    {
        return a[1]<b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end(), myCmp);

        int count=1, prevEnd=pairs[0][1];

        for(int i=1; i<n; i++) 
        {
            if(pairs[i][0]>prevEnd) 
            {
                count++;
                prevEnd=pairs[i][1];
            }
        }

        return count;
    }
};