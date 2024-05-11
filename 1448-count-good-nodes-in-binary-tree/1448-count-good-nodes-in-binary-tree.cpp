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
    void func(TreeNode* root, int &count, int maxi)
    {
        if(root==nullptr)
        {
            return;
        }

        if(root->val>=maxi)
        {
            count++;

            maxi = max(maxi, root->val);
        }

        func(root->left, count, maxi);
        func(root->right, count, maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root)
        {
            int count=1;

            func(root->left, count, root->val);
            func(root->right, count, root->val);

            return count;
        }

        return 0;
    }
};