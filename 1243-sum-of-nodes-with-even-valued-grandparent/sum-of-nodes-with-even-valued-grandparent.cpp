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
    int sum=0;
    void grandParent(TreeNode* root, int level)
    {
        if(!root)
        {
            return;
        }

        if(level==2)
        {
            sum+=root->val;
            return;
        }

        grandParent(root->left, level+1);
        grandParent(root->right, level+1);
    }

    void preorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }

        if(root->val%2==0)
        {
            grandParent(root, 0);
        }

        preorder(root->left);
        preorder(root->right);
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        preorder(root);

        return sum;
    }
};