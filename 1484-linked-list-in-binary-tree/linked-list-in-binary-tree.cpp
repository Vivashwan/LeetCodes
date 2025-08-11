/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPathHelper(ListNode* curr, TreeNode* root) {
        if(!curr)
        { 
            return true; 
        }

        if(!root)
        { 
            return false; 
        }
        
        if(curr->val==root->val) 
        {
            return isSubPathHelper(curr->next, root->left) || isSubPathHelper(curr->next, root->right);
        }
        
        return false;
    }

public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
        { 
            return false; 
        }

        return isSubPathHelper(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};