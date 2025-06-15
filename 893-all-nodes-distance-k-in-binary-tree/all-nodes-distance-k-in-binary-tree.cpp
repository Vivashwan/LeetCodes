/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void findParent(TreeNode* root, unordered_map<int, TreeNode*>&parentOf)
    {
        if(!root)
        {
            return;
        }

        if(root->left)
        {
            parentOf[root->left->val]=root;
            findParent(root->left, parentOf);
        }

        if(root->right)
        {
            parentOf[root->right->val]=root;
            findParent(root->right, parentOf);
        }
    }

    void dfs(TreeNode* root, int k, unordered_map<int, TreeNode*>&parentOf, unordered_set<TreeNode*>&visited, vector<int>&res)
    {
        if(!root || visited.find(root)!=visited.end())
        {
            return;
        }

        visited.insert(root);

        if(k==0)
        {
            res.push_back(root->val);
            return;
        }

        dfs(root->left, k-1, parentOf, visited, res);
        dfs(root->right, k-1, parentOf, visited, res);
        dfs(parentOf[root->val], k-1, parentOf, visited, res);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root)
        {
            return {};
        }

        unordered_map<int, TreeNode*>parentOf;
        
        findParent(root, parentOf);

        vector<int>res; 

        unordered_set<TreeNode*>visited;

        dfs(target, k, parentOf, visited, res);

        return res;
    }
};