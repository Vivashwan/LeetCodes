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
    vector<TreeNode*>res;
    void func(TreeNode* root)
    {
        if(root)
        {
            func(root->left);
            res.push_back(root);
            func(root->right);
        }
    }
public:
    int countNodes(TreeNode* root) {
        func(root);

        return res.size();
    }
};