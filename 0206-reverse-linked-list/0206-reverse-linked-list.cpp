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
    ListNode* func(ListNode* curr, ListNode* prev)
    {
        if(curr==nullptr)
        {
            return prev;
        }

        ListNode* next=curr->next;
        curr->next=prev;

        return func(next, curr);
    }
public:
    ListNode* reverseList(ListNode* head) {
        return func(head, nullptr);
    }
};