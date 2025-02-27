class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {     
        int ans = 1;
        int smaller = 1;
        int larger = 1;

        for (int i = 0; i < arr.size() - 1; ++i) 
        {
            smaller = arr[i] < arr[i + 1] ? smaller + 1 : 1;
            larger = arr[i] > arr[i + 1] ? larger + 1 : 1;
            
            ans = max(ans, max(smaller, larger));
            swap(smaller, larger);
        }
        
        return ans;
    }
};