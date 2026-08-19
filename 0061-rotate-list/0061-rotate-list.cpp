class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0)
            return head;

        int n = 1;
        ListNode* count = head;

        while (count->next != nullptr) {
            count = count->next;
            n++;
        }

        k = k % n;

        if (k == 0)
            return head;

        count->next = head;

        ListNode* newTail = head;

        for (int i = 1; i < n - k; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;

        newTail->next = nullptr;

        return newHead;
    }
};