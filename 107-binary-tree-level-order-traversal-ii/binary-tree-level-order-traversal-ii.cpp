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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
        {
            return {};
        }

        stack<vector<int>>st;

        queue<TreeNode*>q;

        q.push(root);

        while(!q.empty())
        {
            vector<int>temp;
            int n=q.size();

            for(int i=0; i<n; i++)
            {
                auto it=q.front();
                q.pop();

                temp.push_back(it->val);

                if(it->left)
                {
                    q.push(it->left);
                }

                if(it->right)
                {
                    q.push(it->right);
                }
            }

            st.push(temp);
        }

        vector<vector<int>>res;

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};