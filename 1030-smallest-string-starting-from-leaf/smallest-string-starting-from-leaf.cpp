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
    void dfs(TreeNode* node, string& str, string& res) 
    {
        if(node==nullptr)
        { 
            return;
        }

        str.push_back('a'+node->val);

        if(node->left==nullptr && node->right==nullptr) 
        {
            string temp(str.rbegin(), str.rend()); 
            
            if(temp<res)
            {
                res=temp;
            }
        }

        dfs(node->left, str, res);
        dfs(node->right, str, res);

        str.pop_back();
    }

public:
    string smallestFromLeaf(TreeNode* root) {
        string res(1, '~');
        string str;

        dfs(root, str, res);

        return res;
    }
};