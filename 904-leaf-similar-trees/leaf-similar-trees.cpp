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
    void add(TreeNode* root, vector<int>&res)
     {
        if(!root->left && !root->right)
        {
            res.push_back(root->val);
            return;
        }

        if(root->left)
        { 
            add(root->left, res);
        }
        if(root->right)
        { 
            add(root->right, res);
        }
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>a, b;
        add(root1, a);
        add(root2, b);
        return a == b;
    }
};