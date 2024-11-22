class Solution {
private:
    static bool myCmp(vector<int>&a, vector<int>&b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }

        return a[0]<b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n = properties.size();

        sort(properties.begin(), properties.end(), myCmp);

        int count = 0, maxi = INT_MIN;

        for(int i=n-1; i>=0; i--)
        {
            if(properties[i][1]<maxi)
            {
                count++;
            }

            maxi = max(maxi, properties[i][1]);
        }
        
        return count;
    }
};