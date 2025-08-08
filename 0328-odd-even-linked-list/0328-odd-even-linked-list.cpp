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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode* curr=head;
        ListNode* lastOdd=curr;
        ListNode* evenList=new ListNode(0);
        ListNode* evenListHead=evenList;

        while(curr && curr->next)
        {
            ListNode* temp=curr->next->next ? curr->next->next:nullptr;
            evenList->next=curr->next;
            evenList=evenList->next;
            evenList->next=nullptr;

            curr->next=temp;

            if(temp)
            {
                lastOdd=temp;
            }

            curr=temp;
        }

        lastOdd->next=evenListHead->next;

        return head;
    }
};