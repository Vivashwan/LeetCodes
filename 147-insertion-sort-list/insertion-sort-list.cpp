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
    ListNode* sorted;

    void sortedList(ListNode* curr)
    {
        if(sorted==nullptr || curr->val<=sorted->val)
        {
            curr->next=sorted;
            sorted=curr;
        }
        else
        {
            ListNode* temp=sorted;

            while(temp->next && temp->next->val<curr->val)
            {
                temp=temp->next;
            }

            curr->next=temp->next;
            temp->next=curr;
        }
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr=head;
        sorted=nullptr;

        while(curr)
        {
            ListNode* next=curr->next;

            sortedList(curr);

            curr=next;
        }

        head=sorted;
        return head;
    }
};