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
    int val=INT_MAX;
    void func(TreeNode* root, int k, int& count)
    {
        if(!root || val!=INT_MAX)
        {
            return;
        }

        func(root->left, k, count);

        count++;

        if(k==count)
        {
            val=root->val;
            return;
        }

        func(root->right, k, count);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        func(root, k, count);

        return val;
    }
};