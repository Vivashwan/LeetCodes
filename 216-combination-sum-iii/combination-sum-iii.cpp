class Solution {
private:
    vector<vector<int>>res;

    void func(int sum, vector<int>temp, int ind, int k, int n)
    {
        if(sum==n)
        {
            if(temp.size()==k)
            {
                res.push_back(temp);
            }
            return;
        }

        if(temp.size()==k)
        {
            if(sum==n)
            {
                res.push_back(temp);
            }
            return;
        }
        
        for(int i=ind; i<=9; ++i)
        {
            sum+=i;
            temp.push_back(i);
            func(sum, temp, i+1, k, n);
            temp.pop_back();
            sum-=i;
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;

        for(int i=1; i<=9; ++i)
        {
            int sum=i;
            temp.push_back(i);
            func(sum, temp, i+1, k, n);
            temp.pop_back();
        }

        return res;
    }
};