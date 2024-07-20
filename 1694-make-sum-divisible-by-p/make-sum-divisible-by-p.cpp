class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n = nums.size();
        int r = 0 ;
        for(const int& x : nums) r = (r + x) % p ; // handling larger numbers and at the same time we get the remainder too.

        unordered_map<int,int> mp;
        mp[0] = -1 ; // since we store remainder as key and idx as value

        int csum = 0 , len = n ; if(r == 0 ) return 0 ;
        for(int i=0 ; i<n ; i++)
        {
            csum  = (csum + nums[i]) % p; //due to large numbers ,orelse we can use csum+=num[i]

            int rem =  (csum - r + p ) % p ; // handling negative remainders

            if(mp.count(rem)) len = min(len, i - mp[rem]);

            mp[csum] = i ; // store the current remainder in map along with current index
        }
        return len == n ? -1 : len ;
    }
};