class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>inorder(n, 0);

        for(auto it: roads)
        {
            inorder[it[0]]++;
            inorder[it[1]]++;
        }

        sort(inorder.begin(), inorder.end());

        long long importance=1;
        long long res=0;

        for(auto it: inorder)
        {
            res+=it*importance;
            importance++;
        }

        return res;
    }
};