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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==nullptr)
        {
            return {};
        }

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int>v;
            for(int i=0; i<size; i++)
            {
                TreeNode* curr = q.front();
                int value = curr->val;
                v.push_back(value);

                q.pop();

                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    q.push(curr->right);
                }
            }

            ans.push_back(v);
        }

        return ans;
    }
};