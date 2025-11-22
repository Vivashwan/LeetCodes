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
    int func(TreeNode* root, int targetSum, long long currSum, unordered_map<long long, int>&mp)
    {
        if(!root)
        {
            return 0;
        }

        currSum+=root->val;
        long long need=currSum-targetSum;

        int count=0;

        if(mp.count(need)) 
        {
            count+=mp[need];
        }

        mp[currSum]++;

        count+=func(root->left, targetSum, currSum, mp);
        count+=func(root->right, targetSum, currSum, mp);

        mp[currSum]--;

        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int>mp;

        mp[0]=1;

        return func(root, targetSum, 0, mp);
    }
};