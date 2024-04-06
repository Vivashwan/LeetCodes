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
    long long totalSum=0, res=0;
    int MOD=1e9+7;
    void getTotalSum(TreeNode* root)
    {
        if(!root)
        {
            return;
        }

        totalSum+=root->val;
        getTotalSum(root->left);
        getTotalSum(root->right);
    }

    int func(TreeNode* root)
    {   
        if(!root)
        {
            return 0;
        }

        int left = func(root->left), right = func(root->right);

        res = max({res, (totalSum-left)*left, (totalSum-right)*right});

        return left+right+root->val;
    }
public:
    int maxProduct(TreeNode* root) {

        getTotalSum(root);

        func(root);

        return res%MOD;
    }
};