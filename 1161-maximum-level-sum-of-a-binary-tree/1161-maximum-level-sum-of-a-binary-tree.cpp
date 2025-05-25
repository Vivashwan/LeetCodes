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
    int maxLevel=-1, maxSum=INT_MIN;
    void func(TreeNode* root)
    {
        int level=0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            int n=q.size();

            int sum=0; level++;

            for(int i=0; i<n; i++)
            {
                auto it=q.front();
                q.pop();

                sum+=it->val;

                if(it->left)
                {
                    q.push(it->left);
                }

                if(it->right)
                {
                    q.push(it->right);
                }
            }

            if(sum>maxSum)
            {
                maxSum=sum, maxLevel=level;
            }
        }
    }
public:
    int maxLevelSum(TreeNode* root) {
        if(!root)
        {
            return 0;
        }

        func(root);

        return maxLevel;
    }
};