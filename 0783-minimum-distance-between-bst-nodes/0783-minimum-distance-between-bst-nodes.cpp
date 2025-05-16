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
    void inorder(TreeNode* root, TreeNode*& prev, int& mini) {
        if (!root) return;

        inorder(root->left, prev, mini);

        if (prev) {
            mini = min(mini, root->val - prev->val);
        }
        prev = root;

        inorder(root->right, prev, mini);
    }

public:
    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX;
        TreeNode* prev = nullptr;
        inorder(root, prev, mini);
        return mini;
    }
};
