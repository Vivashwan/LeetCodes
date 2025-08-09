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
    vector<int> nextLargerNodes(ListNode* head) {
        int length=0;

        ListNode* temp=head;

        while(temp)
        {
            temp=temp->next;
            length++;
        }

        stack<pair<int, int>>st;
        int index=0;

        vector<int>res(length, 0);

        for(ListNode* curr=head; curr; curr=curr->next)
        {
            if(st.empty() || curr->val<st.top().first)
            {
                st.push({curr->val, index});
            }
            else
            {
                while(!st.empty() && curr->val>st.top().first)
                {
                    res[st.top().second]=curr->val;
                    st.pop();
                }

                st.push({curr->val, index});
            }

            index++;
        }

        return res;
    }
};