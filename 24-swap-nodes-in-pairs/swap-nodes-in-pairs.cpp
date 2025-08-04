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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode dummy(0, head);

        ListNode* curr=&dummy;
        ListNode* fast=&dummy;

        fast=fast->next->next;

        while(fast)
        {
            ListNode* nextSlot=fast->next;
            ListNode* middleOne=curr->next;

            middleOne->next=nextSlot;
            
            curr->next=fast;
            fast->next=middleOne;

            fast=(nextSlot && nextSlot->next) ? nextSlot->next : nullptr;
            curr=middleOne;
        }

        return dummy.next;
    }
};