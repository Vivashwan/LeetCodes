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
    vector<TreeNode*>func(int start, int end)
    {
        vector<TreeNode*>allTrees;

        if(start>end)
        {
            allTrees.push_back(nullptr);
            return allTrees;
        }

        for(int i=start; i<=end; i++)
        {
            vector<TreeNode*>leftChild=func(start, i-1);
            vector<TreeNode*>rightChild=func(i+1, end);

            for(auto it1: leftChild)
            {
                for(auto it2: rightChild)
                {
                    TreeNode* root=new TreeNode(i);
                    root->left=it1;
                    root->right=it2;

                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
        {
            return {nullptr};
        }

        return func(1, n);

    }
};