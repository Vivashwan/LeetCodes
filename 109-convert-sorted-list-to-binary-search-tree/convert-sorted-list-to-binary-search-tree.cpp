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
    ListNode* currentNode;
    int countNodes(ListNode* head)
    {
        int count=0;

        while(head)
        {
            count++;
            head=head->next;
        }

        return count;
    }

    TreeNode* func(int start, int end)
    {
        if(start>end)
        {
            return nullptr;
        }

        int mid = start+(end-start)/2;

        TreeNode* leftTree = func(start, mid-1);
        TreeNode* root = new TreeNode(currentNode->val);
        root->left = leftTree;
        currentNode=currentNode->next;
        root->right = func(mid+1, end);

        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = countNodes(head);

        currentNode=head;

        return func(0, n-1);
    }
};