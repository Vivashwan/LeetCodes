class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>cnt(value, 0);

        for(int x: nums)
        {
            int r=((x % value) + value) % value;
            cnt[r]++;
        }

        int k=0;

        while(true) 
        {
            int r=k%value;

            if(cnt[r]==0) 
            {
                return k;
            }

            cnt[r]--;
            k++;
        }
    }
};
