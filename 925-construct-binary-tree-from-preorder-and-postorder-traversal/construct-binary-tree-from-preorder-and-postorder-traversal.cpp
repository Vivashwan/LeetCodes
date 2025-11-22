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
    TreeNode* func(vector<int>&preOrder, unordered_map<int, int>&postMap, int& preIndex, int postStart, int postEnd)
    {
        if(preIndex>=preOrder.size() || postStart>postEnd)
        {
            return nullptr;
        }

        TreeNode* root=new TreeNode(preOrder[preIndex]);
        preIndex++;

        if(postStart==postEnd)
        {
            return root;
        }

        int nextLeftVal=preOrder[preIndex];
        int lastLeft=postMap[nextLeftVal];

        root->left=func(preOrder, postMap, preIndex, postStart, lastLeft);
        root->right=func(preOrder, postMap, preIndex, lastLeft+1, postEnd-1);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postOrder) {
        unordered_map<int, int>postMap;

        for(int i=0; i<postOrder.size(); i++)
        {
            postMap[postOrder[i]]=i;
        }

        int preIndex=0;

        return func(preorder, postMap, preIndex, 0, postOrder.size()-1);
    }
};