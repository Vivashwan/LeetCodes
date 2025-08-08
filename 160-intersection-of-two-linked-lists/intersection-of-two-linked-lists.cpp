/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA)
        {
            return headB;
        }

        if(!headB)
        {
            return headA;
        }

        ListNode* currA=headA;
        int length1=0;

        while(currA)
        {
            length1++;
            currA=currA->next;
        }

        ListNode* currB=headB;
        int length2=0;

        while(currB)
        {
            length2++;
            currB=currB->next;
        }

        currA=headA, currB=headB;

        if(length1>length2)
        {
            int diff=length1-length2;

            while(diff--)
            {
                currA=currA->next;
            }
        }
        else if(length2>length1)
        {
            int diff=length2-length1;

            while(diff--)
            {
                currB=currB->next;
            }
        }

        while(currA && currB && currA!=currB)
        {
            currA=currA->next;
            currB=currB->next;
        }

        return currA;
    }
};