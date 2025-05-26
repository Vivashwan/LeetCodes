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
    int count=0;

    vector<int>func(TreeNode* root, int distance)
    {
        if(!root)
        {
            return {0};
        }

        if(!root->left && !root->right)
        {
            return {1};
        }

        vector<int>left=func(root->left, distance);
        vector<int>right=func(root->right, distance);

        for(auto u: left)
        {
            for(auto v: right)
            {
                if(u>0 && v>0)
                {
                    if(u+v<=distance)
                    {
                        count++;
                    }  
                }
            }
        } 

        vector<int>res;  

        for(auto it: left)
        {
            if(it>0 && it<distance)
            {
                res.push_back(it+1);
            } 
        }

        for(auto it: right)
        {
            if(it>0 && it<distance)
            {
                res.push_back(it+1);
            }
        }  

        return res;   
    }

public:
    int countPairs(TreeNode* root, int distance) {
        func(root, distance);

        return count;
    }
};