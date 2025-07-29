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
    void solve(TreeNode* root, int targetSum, vector<int>&temp, vector<vector<int>>&res)
    {
        if(root==nullptr)
        {
            return;
        }

        temp.push_back(root->val);

        if(root->left==nullptr && root->right==nullptr && targetSum==root->val) 
        {
            res.push_back(temp);
        }

        solve(root->left, targetSum-root->val, temp, res);
        solve(root->right, targetSum-root->val, temp, res);
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>temp;

        solve(root, targetSum, temp, res);

        return res;
    }
};