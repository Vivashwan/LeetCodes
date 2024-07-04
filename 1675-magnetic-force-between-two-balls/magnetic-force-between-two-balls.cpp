class Solution {
private:
    int func(int val, vector<int>&position, int m, int n)
    {
        int count = 1;

        int last = position[0];

        for(int i=1; i<n; i++)
        {
            if(position[i]-last>=val)
            {
                count++, last = position[i];
            }

            if(count>=m)
            {
                return true;
            }
        }

        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());

        int low = 1, high = (position[n-1]-position[0])/(m-1);

        int ans;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(func(mid, position, m, n))
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;
    }
};