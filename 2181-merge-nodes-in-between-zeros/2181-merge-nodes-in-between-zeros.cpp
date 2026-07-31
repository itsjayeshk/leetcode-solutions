class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {

        ListNode* modify = head->next;
        ListNode* curr = head->next;

        while (curr) {
            int sum = 0;

            while (curr && curr->val != 0) {
                sum += curr->val;
                curr = curr->next;
            }

            if (curr) {
                modify->val = sum;
                modify->next = curr->next;
                modify = modify->next;
                curr = curr->next;
            }
        }

        return head->next;
    }
};