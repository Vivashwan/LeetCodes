class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        
        int minIndex=min_element(nums.begin(), nums.end())-nums.begin();
        int maxIndex=max_element(nums.begin(), nums.end())-nums.begin();

        if(minIndex>maxIndex)
        { 
            swap(minIndex, maxIndex);
        }

        return min({ maxIndex+1, n-minIndex, (minIndex+1) + (n-maxIndex)});
    }
};