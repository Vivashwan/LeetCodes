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
    TreeNode* dfs(TreeNode* node, unordered_set<int>&s, vector<TreeNode*>&res)
    {
        if(!node)
        { 
            return nullptr;
        }

        node->left=dfs(node->left, s, res), node->right=dfs(node->right, s, res);

        if(s.count(node->val)) 
        {
            if(node->left)
            { 
                res.push_back(node->left);
            }

            if(node->right)
            { 
                res.push_back(node->right);
            }

            return nullptr;
        }

        return node;
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int>s(to_delete.begin(), to_delete.end());

        vector<TreeNode*>res;

        if(!s.count(root->val)) 
        {
            res.push_back(root);
        }

        dfs(root, s, res);

        return res;
    }
};