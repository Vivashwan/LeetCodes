class Solution {
private:
    void func(int ind, int k, int n, vector<vector<int>>&res, vector<int>temp)
    {
        if(temp.size()==k && n==0)
        {
            res.push_back(temp);
            return;
        }
        else if(temp.size()==k || n<0)
        {
            return;
        }

        for(int i=ind; i<=9; i++)
        {
            temp.push_back(i);
            func(i+1, k, n-i, res, temp);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;

        func(1, k, n, res, temp);

        return res;
    }
};