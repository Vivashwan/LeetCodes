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
    TreeNode* func(vector<int>& preorder, unordered_map<int, int>& postMap, int& preIndex, int postStart, int postEnd)
    {
        if(preIndex>=preorder.size() || postStart>postEnd)
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIndex]);

        preIndex++;

        if(postStart==postEnd)
        {
            return root;
        }

        int leftVal=preorder[preIndex];
        int leftValPos=postMap[leftVal];

        root->left=func(preorder, postMap, preIndex, postStart, leftValPos);
        root->right=func(preorder, postMap, preIndex, leftValPos+1, postEnd-1);

        return root;
    }

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        unordered_map<int, int>postMap;

        for(int i=0; i<postorder.size(); i++)
        {
            postMap[postorder[i]]=i;
        }

        int preIndex=0;

        return func(preorder, postMap, preIndex, 0, postorder.size()-1);
    }
};