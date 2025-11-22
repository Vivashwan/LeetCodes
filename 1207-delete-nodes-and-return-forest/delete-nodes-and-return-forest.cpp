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
    TreeNode* func(TreeNode* root, unordered_set<int>&s, vector<TreeNode*>&res)
    {
        if(!root)
        {
            return nullptr;
        }

        root->left=func(root->left, s, res);
        root->right=func(root->right, s, res);

        if(s.count(root->val))
        {
            if(root->left)
            {
                res.push_back(root->left);
            }

            if(root->right)
            {
                res.push_back(root->right);
            }

            return nullptr;
        }

        return root;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>s(to_delete.begin(), to_delete.end());

        vector<TreeNode*>res;

        if(!s.count(root->val))
        {
            res.push_back(root);
        }

        func(root, s, res);

        return res;
    }
};