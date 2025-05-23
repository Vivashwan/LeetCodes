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
    void func(TreeNode* root, int& count, int maxi)
    {
        if(!root)
        {
            return;
        }

        if(root->val>=maxi)
        {
            count++, maxi=root->val;
        }

        func(root->left, count, maxi);
        func(root->right, count, maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        int count=0, maxi=root->val;

        func(root, count, maxi);

        return count;
    }
};