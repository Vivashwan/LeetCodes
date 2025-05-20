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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>res;

        stack<TreeNode*>st1, st2;

        TreeNode* curr1=root1, *curr2=root2;

        while(!st1.empty() || !st2.empty() || curr1!=nullptr || curr2!=nullptr)
        {
            while(curr1)
            {
                st1.push(curr1);
                curr1=curr1->left;
            }

            while(curr2)
            {
                st2.push(curr2);
                curr2=curr2->left;
            }

            if(st2.empty() || (!st1.empty() && st1.top()->val<=st2.top()->val))
            {
                curr1=st1.top();
                st1.pop();
                res.push_back(curr1->val);

                curr1=curr1->right;
            }
            else
            {
                curr2=st2.top();
                st2.pop();
                res.push_back(curr2->val);

                curr2=curr2->right;
            }
        }

        return res;
    }
};