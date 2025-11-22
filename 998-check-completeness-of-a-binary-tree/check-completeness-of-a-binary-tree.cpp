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
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;

        q.push(root);

        bool end=false;

        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            if(!it)
            {
                end=true;
            }
            else
            {
                if(end)
                {
                    return false;
                }

                q.push(it->left);
                q.push(it->right);
            }
        }

        return true;
    }
};