class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());

        int groups=0, prevSize=0;
        long long prevSum=0, currSum=0;

        int currSize=0;

        for(auto g: grades) 
        {
            currSize++;
            currSum+=g;

            if(currSize>prevSize && currSum>prevSum) 
            {
                groups++;

                prevSize=currSize;
                prevSum=currSum;

                currSize=0;
                currSum=0;
            }
        }

        return groups;
    }
};