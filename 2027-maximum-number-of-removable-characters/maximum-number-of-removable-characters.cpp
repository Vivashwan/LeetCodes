class Solution {
private:
    bool check(string s, string p, vector<int>&removable, int mid)
    {
        for(int i=0; i<mid; i++)
        {
            s[removable[i]]='*';
        }

        int j=0, k=0;

        while(j<s.length() && k<p.length())
        {
            if(s[j]==p[k])
            {
                k++;
            }

            j++;
        }

        return k==p.length();
    }
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0, high = removable.size();

        int ans = 0;

        while(low<=high)
        {
            int mid = low+(high-low)/2;

            if(check(s, p, removable, mid))
            {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        return ans;
    }
};