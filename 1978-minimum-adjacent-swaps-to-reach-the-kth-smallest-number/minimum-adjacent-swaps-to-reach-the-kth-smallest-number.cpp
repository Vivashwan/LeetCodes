class Solution {
private:
    void nextPermutation(string &target)
    {
        int n=target.length();

        int i=n-2;

        while(i>=0 && target[i]>=target[i+1])
        {
            i--;
        }

        if(i<0) 
        {
            sort(target.begin(), target.end());
            return;
        }

        int j=n-1;

        while(j>=i && target[j]<=target[i])
        {
            j--;
        }

        swap(target[i], target[j]);

        reverse(target.begin()+i+1, target.end());
    }
public:
    int getMinSwaps(string num, int k) {
        string target=num;
        int n=num.length();

        while(k--)
        {
            nextPermutation(target);
        }

        int res=0;

        for(int i=0; i<n; i++)
        {
            if(target[i]==num[i])
            {
                continue;
            }

            int j=i;

            while(j<n && target[i]!=num[j])
            {
                j++;
            }

            while(j>i)
            {
                swap(num[j], num[j-1]);
                j--;
                res++;
            }
        }

        return res;
    }
};