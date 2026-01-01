class Solution {
private:
    bool checker(vector<int>&quantities, int n, int mid)
    {
        int stores=0, m=quantities.size();

        for(int j=0; j<m; j++)
        {
            if(stores>n)
            {
                return false;
            }

            if(quantities[j]%mid!=0)
            {
                stores+=(quantities[j]/mid)+1;
            }
            else stores+=quantities[j]/mid;
        }
        
        return stores<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1, high=*max_element(quantities.begin(), quantities.end());

        int ans;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(checker(quantities, n, mid))
            {
                ans=mid, high=mid-1;
            }
            else low=mid+1;
        }

        return ans;
    }
};