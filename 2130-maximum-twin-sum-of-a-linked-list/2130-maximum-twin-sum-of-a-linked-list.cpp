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
    int pairSum(ListNode* head) {
        ListNode* curr=head;

        int n=0;

        while(curr)
        {
            curr=curr->next;
            n++;
        }

        if(n==2)
        {
            return head->val+head->next->val;
        }

        int mid=n/2;

        curr=head;

        for(int i=0; i<mid-1; i++)
        {
            curr=curr->next;
        }

        ListNode* nextList=curr->next, *prev=nullptr;
        curr->next=nullptr;

        while(nextList)
        {
            ListNode*next=nextList->next;
            nextList->next=prev;

            prev=nextList;
            nextList=next;
        }

        curr=head;
        int maxim=INT_MIN;

        while(mid!=0)
        {
            maxim=max(maxim, curr->val+prev->val);

            mid--;
            curr=curr->next;
            prev=prev->next;
        }

        return maxim;
    }
};