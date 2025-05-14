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
    int func(TreeNode* root, int low, int high) {
        
        if(!root)
        { 
            return 0;
        }

        if(root->val<low)
        {    
            return func(root->right, low, high);
        }

        if(root->val>high)
        {    
            return func(root->left, low, high);
        }

        return root->val + func(root->left, low, high) + func(root->right, low, high);
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        return func(root, low, high);
    }
};
