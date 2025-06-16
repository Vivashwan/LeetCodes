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
    int func(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }

        return 1+max(func(root->left), func(root->right));
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(!root)
        {
            return nullptr;
        }

        int leftCount=func(root->left), rightCount=func(root->right);

        if(leftCount==rightCount)
        {
            return root;
        }
        else if(leftCount>rightCount)
        {
            root = subtreeWithAllDeepest(root->left);
        }
        else
        {
            root = subtreeWithAllDeepest(root->right);
        }

        return root;
    }
};