/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<TreeNode*, int>mp;
    int func(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }

        if(!mp.count(root))
        {
            mp[root]=max(func(root->left), func(root->right))+1;
        }

        return mp[root];
    }
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root)
        {
            return nullptr;
        }

        int left=func(root->left), right=func(root->right);

        if(left==right)
        {
            return root;
        }
        else if(left>right)
        {
            return lcaDeepestLeaves(root->left);
        }
        else
        {
            return lcaDeepestLeaves(root->right);
        }
    }
};