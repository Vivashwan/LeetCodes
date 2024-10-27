class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
         bool canMatch0 = false, canMatch1 = false, canMatch2 = false;

        for (auto triplet: triplets) 
        {
            if(triplet[0]<=target[0] && triplet[1]<=target[1] && triplet[2]<=target[2])        {
                if(triplet[0] == target[0]) canMatch0 = true;
                if(triplet[1] == target[1]) canMatch1 = true;
                if(triplet[2] == target[2]) canMatch2 = true;
            }
        }

        return canMatch0 && canMatch1 && canMatch2;
    }
};