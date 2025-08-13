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
    int gcd(int a, int b)
    {
        while(b!=0)
        {
            int temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }

public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head)
        { 
            return nullptr;
        }

        ListNode* curr=head;

        while(curr->next) 
        {
            int gcdValue=gcd(curr->val, curr->next->val);

            curr->next=new ListNode(gcdValue, curr->next);
            curr=curr->next->next;
        }

        return head;
    }
};