class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n = arr.size();

        sort(arr.begin(), arr.end());
        
        int mid = (n-1)/2;

        int median = arr[mid];


        sort(arr.begin(), arr.end(), [median](int a, int b) {
            int diffA = abs(a - median);
            int diffB = abs(b - median);
            if (diffA == diffB) {
                return a > b;
            }
            return diffA > diffB;
        });

        vector<int> res(arr.begin(), arr.begin() + k);

        return res;
    }
};