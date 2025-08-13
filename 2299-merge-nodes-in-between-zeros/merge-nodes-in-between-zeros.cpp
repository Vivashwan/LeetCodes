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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* curr=head;
        ListNode* temp=head->next;

        int total=0;

        while(temp)
        {
            if(temp->val==0)
            {
                curr->next=new ListNode(total);
                curr=curr->next;
                total=0;
            }

            total+=temp->val;
            temp=temp->next;
        }

        return head->next;
    }
};