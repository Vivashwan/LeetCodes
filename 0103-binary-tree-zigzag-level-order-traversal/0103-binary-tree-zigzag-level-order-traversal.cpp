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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }

        queue<TreeNode*>q;
        q.push(root);

        bool flag = false;

        vector<vector<int>>res;

        while(!q.empty())
        {
            int n = q.size();

            vector<int>temp;

            for(int i=0; i<n; i++)
            {
                TreeNode* curr = q.front();
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

            flag = !flag;

            if(flag == false)
            {
                reverse(temp.begin(), temp.end());
            } 
            res.push_back(temp);   
        }
        return res;
    }
};