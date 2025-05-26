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
    TreeNode* func(TreeNode* root, int val, int depth, int curr)
    {
        if(!root)
        {
            return nullptr;
        }

        if(curr==depth-1)
        {
            TreeNode* currLeft= new TreeNode(val);
            TreeNode* currRight= new TreeNode(val);

            currLeft->left=root->left;
            currRight->right=root->right;

            root->left=currLeft, root->right=currRight;

            return root;
        }

        root->left=func(root->left, val, depth, curr+1);
        root->right=func(root->right, val, depth, curr+1);

        return root;
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1)
        {
            TreeNode* res=new TreeNode(val);
            res->left=root;

            return res;
        }

        return func(root, val, depth, 1);
    }
};