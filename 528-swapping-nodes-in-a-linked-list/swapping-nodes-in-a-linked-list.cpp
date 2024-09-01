class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int countNodes = 0;
        ListNode* temp = head;
        ListNode* curr1 = nullptr;
        ListNode* curr2 = nullptr;

        // First pass to find the length of the list and locate the k-th node from the beginning
        while (temp) {
            countNodes++;
            if (countNodes == k) {
                curr1 = temp; // found k-th node from the beginning
            }
            temp = temp->next;
        }

        int rightK = countNodes - k + 1; // calculate k-th node from the end
        countNodes = 0;
        temp = head;

        // Second pass to locate the k-th node from the end
        while (temp) {
            countNodes++;
            if (countNodes == rightK) {
                curr2 = temp; // found k-th node from the end
                break;
            }
            temp = temp->next;
        }

        // Swap values of the k-th node from the beginning and k-th node from the end
        if (curr1 && curr2) {
           swap(curr1->val, curr2->val);
        }

        return head;
    }
};
