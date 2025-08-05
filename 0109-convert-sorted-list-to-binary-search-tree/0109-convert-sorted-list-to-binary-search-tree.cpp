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
    TreeNode* func(ListNode* head, ListNode* tail)
    {
        if(head==tail)
        {
            return nullptr;
        }

        ListNode* fast=head, *slow=head;

        while(fast!=tail && fast->next!=tail)
        {
            fast=fast->next->next;
            slow=slow->next;
        }

        TreeNode* node=new TreeNode(slow->val);

        node->left=func(head, slow);
        node->right=func(slow->next, tail);

        return node;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return func(head, nullptr);
    }
};