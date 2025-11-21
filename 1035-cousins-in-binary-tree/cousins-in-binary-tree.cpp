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
    TreeNode* parentX=nullptr, *parentY=nullptr;
    int depthX=0, depthY=0;

    void func(TreeNode* root, TreeNode* parent, int x, int y, int depth)
    {
        if(!root)
        {
            return;
        }

        if(root->val==x)
        {
            parentX=parent;
            depthX=depth;
        }

        if(root->val==y)
        {
            parentY=parent;
            depthY=depth;
        }

        func(root->left, root, x, y, depth+1);
        func(root->right, root, x, y, depth+1);
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root)
        {
            return false;
        }

        func(root, nullptr, x, y, 0);

        if(parentX && parentY)
        {
            if(parentX->val==parentY->val)
            {
                return false;
            }
            else if(depthX!=depthY)
            {
                return false;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};