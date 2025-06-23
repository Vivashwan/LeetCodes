class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n=arr.size();

        if(m==n)
        {
            return n;
        }

        vector<int>length(n+2, 0), count(n+1, 0);

        int res=-1;

        for(int step=0; step<n; step++)
        {
            int pos=arr[step];

            int left=length[pos-1], right=length[pos+1];

            int total=left+right+1;

            if(left>0)
            {
                count[left]--;
            }

            if(right>0)
            {
                count[right]--;
            }

            length[pos-left]=length[pos]=length[pos+right]=total;

            count[total]++;

            if(count[m]>0)
            {
                res=step+1;
            }
        }       

        return res;
    }
};