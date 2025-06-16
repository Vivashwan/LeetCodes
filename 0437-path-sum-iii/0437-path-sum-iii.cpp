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
    int dfs(TreeNode* node, long long currSum, int target, unordered_map<long long, int>& prefixSumCount) 
    {
        if(!node)
        { 
            return 0;
        }

        currSum+=node->val;
        int count=prefixSumCount[currSum-target];

        prefixSumCount[currSum]++;

        count+=dfs(node->left, currSum, target, prefixSumCount);
        count+=dfs(node->right, currSum, target, prefixSumCount);

        prefixSumCount[currSum]--;

        return count;
    }

public:
    int pathSum(TreeNode* root, int targetSum)
    {
        unordered_map<long long, int>prefixSumCount;
        prefixSumCount[0]=1;
        return dfs(root, 0, targetSum, prefixSumCount);
    }
};