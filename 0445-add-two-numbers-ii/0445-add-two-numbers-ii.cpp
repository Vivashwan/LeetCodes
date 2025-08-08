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
    ListNode* reverseLL(ListNode* curr, ListNode* prev)
    {
        if(curr==nullptr)
        {
            return prev;
        }

        ListNode* next = curr->next;
        curr->next = prev;

        return reverseLL(next, curr);
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* newL1 = reverseLL(l1, nullptr);
        ListNode* newL2 = reverseLL(l2, nullptr);

        ListNode* newArr = new ListNode();
        ListNode* curr = newArr;
        long long carry = 0;

        while(newL1!=nullptr || newL2 != nullptr || carry)
        {
            long long sum = 0;

            if(newL1!=nullptr)
            {
                sum+=newL1->val;
                newL1 = newL1->next;
            }

            if(newL2!=nullptr)
            {
                sum+=newL2->val;
                newL2 = newL2->next;
            }

            sum +=carry;
            carry = (sum)/10; 

            ListNode* temp = new ListNode((sum)%10); 

            curr->next = temp;
            curr = curr->next;         
        }

        ListNode* ans = reverseLL(newArr->next, nullptr);

        return ans;

    }
};