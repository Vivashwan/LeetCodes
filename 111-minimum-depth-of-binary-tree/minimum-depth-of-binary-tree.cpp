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
    int minDepth(TreeNode* root) {

        if(root==nullptr)
        {
            return 0;
        }

        queue<TreeNode*>q;

        q.push(root);
        int depth = 0;

        while(!q.empty())
        {   
           int levelDepth = q.size();

            depth++;

            for(int i=0; i<levelDepth; i++)
            {
                auto it = q.front();
                q.pop();
                if(it->left==nullptr && it->right == nullptr)
                {
                    return depth;
                }

                if(it->left)
                {
                    q.push(it->left);
                }
                if(it->right)
                {
                    q.push(it->right);
                }
            }


        }

        return depth;
    }
};