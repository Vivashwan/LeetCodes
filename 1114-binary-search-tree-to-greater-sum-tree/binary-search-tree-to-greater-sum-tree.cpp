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
    int prev=0;
    void func(TreeNode* root)
    {
        if(!root)
        {
            return;
        }

        func(root->right);

        root->val+=prev;
        prev=root->val;

        func(root->left);
    }

public:
    TreeNode* bstToGst(TreeNode* root) {
        func(root); 

        return root;
    }
};