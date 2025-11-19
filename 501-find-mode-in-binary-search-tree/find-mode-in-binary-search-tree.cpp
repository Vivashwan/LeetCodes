class Solution {
public:
    void func(TreeNode* root, unordered_map<int,int>&mp, int& mx)
    {
        if(!root)
        { 
            return;
        }

        func(root->left, mp, mx);

        mp[root->val]++;
        mx=max(mx, mp[root->val]);

        func(root->right, mp, mx);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        int mx=0;

        func(root, mp, mx);

        vector<int>res;

        for(auto &p: mp) 
        {
            if(p.second==mx)
            { 
                res.push_back(p.first);
            }
        }

        return res;
    }
};
