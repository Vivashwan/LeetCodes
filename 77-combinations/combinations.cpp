class Solution {
private:
    void func(int ind, int n, int k, vector<vector<int>>&res, vector<int>temp)
    {
        if(temp.size()==k)
        {
            res.push_back(temp);
            return;
        }

        for(int i=ind; i<=n; i++)
        {
            temp.push_back(i);
            func(i+1, n, k, res, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>temp;

        func(1, n, k, res, temp);

        return res;
    }
};