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
    int res=0;

    void func(TreeNode* root, int count)
    {
        if(!root)
        {
            res=max(res, count);
            return;
        }

        count++;

        func(root->left, count);
        func(root->right, count);
    }
public:
    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        func(root, 0);

        return res;
    }
};