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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr1 = list1, *curr2 = list2, *tail1 = list1, *tail2 = list2;

        for(int i=0; i<a-1; i++)
        {
            curr1=curr1->next;
        }

        for(int i=0; i<b; i++)
        {
            tail1 = tail1->next;
        }

        ListNode* temp = tail1->next;
        tail1->next = nullptr;

        while(tail2->next!=nullptr)
        {
            tail2=tail2->next;
        }

        tail2->next = temp;

        curr1->next = nullptr;

        curr1->next = curr2;

        return list1;

    }
};