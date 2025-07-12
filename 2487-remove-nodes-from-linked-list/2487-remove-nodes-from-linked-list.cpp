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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=nullptr;

        while(head) 
        {
            ListNode* next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        head=reverse(head); 

        ListNode* curr=head;

        int maxVal=curr->val;

        while(curr && curr->next)
        {
            if(curr->next->val<maxVal)
            {
                curr->next=curr->next->next;
            } 
            else
            {
                curr=curr->next;
                maxVal=curr->val;
            }
        }

        return reverse(head);
    }
};
