class Solution {
public:
    vector<int>v;
    Solution(vector<int>& w) {
        v.push_back(w[0]);

        for(int i=1; i<w.size(); i++)
        {
            v.push_back(v[i-1]+w[i]);
        }
    }
    
    int pickIndex() {
        // We generate a random number between [0,5]
        int random = rand() % v.back();

        // We binary search the prefix sum vector for first v[i] > random
        // That means: "which interval does this random point fall into?"
        auto it = upper_bound(v.begin(), v.end(), random);

        // Return the corresponding index
        return it - v.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */