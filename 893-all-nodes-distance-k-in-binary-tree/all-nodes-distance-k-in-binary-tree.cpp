/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void findParent(TreeNode* root, unordered_map<int, TreeNode*>&mp)
    {
        if(!root)
        {
            return;
        }

        if(root->left)
        {
            mp[root->left->val]=root;
            findParent(root->left, mp);
        }

        if(root->right)
        {
            mp[root->right->val]=root;
            findParent(root->right, mp);
        }
    }

    void func(TreeNode* root, int k, unordered_map<int, TreeNode*>&mp, vector<int>&res, unordered_set<TreeNode*>&visited)
    {
        if(!root || visited.find(root)!=visited.end())
        {
            return;
        }

        visited.insert(root);

        if(k==0)
        {
            res.push_back(root->val);
            return;
        }

        func(root->left, k-1, mp, res, visited);
        func(root->right, k-1, mp, res, visited);
        func(mp[root->val], k-1, mp, res, visited);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*>mp;

        findParent(root, mp);

        vector<int>res;

        unordered_set<TreeNode*>visited;

        func(target, k, mp, res, visited);

        return res;
    }
};