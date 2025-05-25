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
    void levelOrder(TreeNode* root, vector<vector<int>>&res)
    {
        if(!root)
        {
            return;
        }

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp;

            for(int i=0; i<size; i++)
            {
                TreeNode *curr=q.front();
                q.pop();

                temp.push_back(curr->val);
                
                if(curr->left)
                {
                    q.push(curr->left);
                }

                if(curr->right)
                {
                    q.push(curr->right);
                }
            }

            res.insert(res.begin(), temp);    
        }
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;

        levelOrder(root, res);
        return res;
    }
};