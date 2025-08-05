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
    TreeNode* prev=nullptr;

    void func(TreeNode* root)
    {
        if(!root)
        {
            return;
        }

        func(root->right);
        func(root->left);

        root->right=prev;
        root->left=nullptr;

        prev=root;
    }
public:
    void flatten(TreeNode* root) {
        if(!root)
        {
            return;
        }

        func(root);

        return;
    }
};