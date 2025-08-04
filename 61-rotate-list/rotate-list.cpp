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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0)
        {
            return head;
        }

        ListNode* temp=head;

        int count=1;

        while(temp->next)
        {
            count++;
            temp=temp->next;
        }

        k=k%count;

        if(k==0)
        { 
            return head;
        } 
        
        count-=k;

        ListNode* curr=head;

        for(int i=0; i<count-1; i++)
        {
            curr=curr->next;
        }

        ListNode* tempA=curr->next;
        curr->next=nullptr;
        temp->next=head;

        head=tempA;

        return head;
    }
};