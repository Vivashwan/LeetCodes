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
public:
    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true; // An empty tree is considered a valid even-odd tree
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0; // Start from level 0 (root level)

        while (!q.empty()) {
            int n = q.size();
            vector<int> values;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                values.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            if (level % 2 == 0) {
                // Even level: all values must be odd and strictly increasing
                for (int i = 0; i < values.size(); i++) {
                    if (values[i] % 2 == 0) return false;
                    if (i > 0 && values[i] <= values[i - 1]) return false;
                }
            } else {
                // Odd level: all values must be even and strictly decreasing
                for (int i = 0; i < values.size(); i++) {
                    if (values[i] % 2 != 0) return false;
                    if (i > 0 && values[i] >= values[i - 1]) return false;
                }
            }

            level++;
        }

        return true;
    }
};