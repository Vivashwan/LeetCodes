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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* curr=head;
        int length=0;

        while(curr)
        {
            curr=curr->next;
            length++;
        }

        vector<ListNode*>res;

        int base=length/k, extra=length%k;

        curr=head;

        for(int i=0; i<k; i++)
        {
            res.push_back(curr);

            int partSize=base+(extra>0 ? 1:0);

            if(extra>0)
            {
                extra--;
            }

            for(int j=0; j<partSize-1 && curr; j++)
            {
                curr=curr->next;
            }

            if(curr)
            {
                ListNode* next=curr->next;
                curr->next=nullptr;
                curr=next;
            }
        }

        return res;
    }
};