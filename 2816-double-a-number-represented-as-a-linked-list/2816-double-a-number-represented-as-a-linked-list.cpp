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
public:
    ListNode* doubleIt(ListNode* head) {
        head=reverse(head);

        ListNode* dummy=new ListNode();
        ListNode* cur=dummy;
        int carry=0;

        while(head)
        {
            int sum=head->val*2+carry;
            carry=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            head=head->next;
        }

        if(carry>0)
        {
            cur->next=new ListNode(carry);
        }

        return reverse(dummy->next);
    }
};