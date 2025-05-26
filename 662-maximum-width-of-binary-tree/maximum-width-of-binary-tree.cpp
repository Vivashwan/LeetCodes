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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        queue<pair<TreeNode*, long long>>q;

        q.push({root, 0});

        int maxim=0;

        while(!q.empty())
        {
            int n=q.size();

            long long first=q.front().second;
            long long last=q.back().second;

            maxim=max(maxim, int(last-first+1));

            for(int i=0; i<n; i++)
            {
                auto [node, index]=q.front();
                q.pop();

                index-=first;

                if(node->left)
                {
                    q.push({node->left, 2*index});
                }

                if(node->right)
                {
                    q.push({node->right, 2*index+1});
                }
            }
        }

        return maxim;
    }
};