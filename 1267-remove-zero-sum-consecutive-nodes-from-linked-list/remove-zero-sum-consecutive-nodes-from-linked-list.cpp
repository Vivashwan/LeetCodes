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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy=new ListNode(0, head);

        unordered_map<int, ListNode*>mp;

        ListNode* curr=dummy;
        int sum=0;

        while(curr)
        {
            sum+=curr->val;

            if(mp[sum])
            {
                curr=mp[sum]->next;

                int temp=sum+curr->val;

                while(temp!=sum)
                {
                    mp.erase(temp);
                    curr=curr->next;
                    temp+=curr->val;
                }

                mp[sum]->next=curr->next;
            }
            else
            {
                mp[sum]=curr;
            }

            curr=curr->next;
        }

        return dummy->next;
    }
};