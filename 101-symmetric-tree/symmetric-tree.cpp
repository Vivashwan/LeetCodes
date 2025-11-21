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
    bool func(TreeNode* root1, TreeNode* root2)
    {
        if(root1==nullptr && root2==nullptr)
        {
            return true;
        }

        if(root1==nullptr || root2==nullptr)
        {
            return false;
        }

        return (root1->val == root2->val) && func(root1->left, root2->right) && func(root1->right, root2->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
        {
            return true;
        }

        return func(root, root);
    }
};