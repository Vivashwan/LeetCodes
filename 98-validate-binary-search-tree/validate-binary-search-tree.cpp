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
    void func(TreeNode* root, vector<int>&temp)
    {
        if(!root)
        {
            return;
        }

        func(root->left, temp);

        temp.push_back(root->val);

        func(root->right, temp);
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int>temp;

        func(root, temp);

        for(int i=0; i<temp.size()-1; i++)
        {
            if(temp[i]>=temp[i+1])
            {
                return false;
            }
        }

        return true;
    }
};