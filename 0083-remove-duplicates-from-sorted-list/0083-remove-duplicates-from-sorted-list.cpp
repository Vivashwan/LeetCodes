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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy=new ListNode(0, head);
        ListNode* curr=dummy;

        int dupVal=-101;
        while(head)
        {
            if(head->val != dupVal)
            {   
                curr->next=new ListNode(head->val);
                curr=curr->next;
                dupVal=head->val;
            }

            head=head->next;
        }

        return dummy->next;
    }
};