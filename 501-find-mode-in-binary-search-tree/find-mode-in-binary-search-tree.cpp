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
    int currentVal;
    int currentCount;
    int maxCount;
    vector<int> modes;

    void inorder(TreeNode* node) {
        if (!node) return;

        inorder(node->left);

        if (node->val == currentVal) {
            currentCount++;
        } else {
            currentVal = node->val;
            currentCount = 1;
        }

        if (currentCount == maxCount) {
            modes.push_back(currentVal);
        } else if (currentCount > maxCount) {
            modes.clear();
            modes.push_back(currentVal);
            maxCount = currentCount;
        }

        inorder(node->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        currentVal = INT_MIN;
        currentCount = 0;
        maxCount = 0;
        modes.clear();

        inorder(root);
        return modes;
    }
};