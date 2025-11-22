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
    void func(TreeNode* root, TreeNode*& ans)
    {
        if(!root)
        {
            return;
        }

        func(root->left, ans);

        ans->right=new TreeNode(root->val);

        ans=ans->right;

        func(root->right, ans);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp;

        TreeNode* ans=new TreeNode();

        temp=ans;

        func(root, ans);

        return temp->right;
    }
};