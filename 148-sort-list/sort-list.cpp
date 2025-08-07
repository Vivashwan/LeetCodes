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
private:
    ListNode* split(ListNode* head, int size)
    {
        while(--size && head)
        {
            head=head->next;
        }

        if(!head)
        {
            return nullptr;
        }

        ListNode* second=head->next;
        head->next=nullptr;

        return second;
    }

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* tail)
    {
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                tail->next=l1;
                l1=l1->next;
            }
            else 
            {
                tail->next=l2;
                l2=l2->next;
            }

            tail=tail->next;
        }

        tail->next=l1?l1:l2;

        while(tail->next)
        {
            tail=tail->next;
        }

        return tail;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        int length=0;
        ListNode* curr=head;

        while(curr)
        {
            length++;
            curr=curr->next;
        }

        ListNode* dummy=new ListNode(0, head);

        for(int size=1; size<length; size*=2)
        {
            ListNode* curr=dummy->next;
            ListNode* tail=dummy;

            while(curr)
            {
                ListNode* left=curr;
                ListNode* right=split(left, size);
                curr=split(right, size);

                tail=merge(left, right, tail);
            }
        }

        return dummy->next;
    }
};