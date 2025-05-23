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
    int sum=0;

    void func(TreeNode* root, int val)
    {
        if(!root)
        {
            return;
        }

        val= val<<1 | root->val;

        if(!root->left && !root->right)
        {
            sum+=val;
            return;
        }

        func(root->left, val);
        func(root->right, val);
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        int val=0;

        func(root, 0);

        return sum;
    }
};