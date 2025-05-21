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
    int count=0;
    void func(TreeNode* root)
    {
        if(root)
        {
            func(root->left);
            count++;
            func(root->right);
        }
    }
public:
    int countNodes(TreeNode* root) {
        func(root);

        return count;
    }
};