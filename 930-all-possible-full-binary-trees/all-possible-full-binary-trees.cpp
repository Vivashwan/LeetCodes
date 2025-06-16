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
    unordered_map<int, vector<TreeNode*>>memo;
    
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(memo.count(n))
        {
            return memo[n];
        }

        vector<TreeNode*>res;

        if(n==1)
        {
            res.push_back(new TreeNode(0));
            return res;
        }

        for(int left=1; left<n; left+=2)
        {
            int right=n-1-left;

            vector<TreeNode*>leftNode=allPossibleFBT(left);
            vector<TreeNode*>rightNode=allPossibleFBT(right);

            for(auto l: leftNode)
            {
                for(auto r: rightNode)
                {
                    TreeNode* root = new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    res.push_back(root);
                }
            }
        }

        return memo[n]=res;
    }   
};