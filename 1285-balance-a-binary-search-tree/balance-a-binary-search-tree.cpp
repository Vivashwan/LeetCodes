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
    void inorder(TreeNode* root, vector<TreeNode*>&nodes)
    {
        if(!root)
        {
            return;
        }

        inorder(root->left, nodes);
        nodes.push_back(root);
        inorder(root->right, nodes);
    }

    TreeNode* func(vector<TreeNode*>&nodes, int start, int end)
    {
        if(start>end)
        {
            return nullptr;
        }

        int mid = start+(end-start)/2;

        TreeNode* root = nodes[mid];

        root->left = func(nodes, start, mid-1);
        root->right = func(nodes, mid+1, end);

        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*>nodes;
        inorder(root, nodes);

        return func(nodes, 0, nodes.size()-1);
    }
};