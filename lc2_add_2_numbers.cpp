class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> list1;
        vector<int> list2;
        vector<int> ans;

        while (l1) {
            list1.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            list2.push_back(l2->val);
            l2 = l2->next;
        }

        int n1 = list1.size();
        int n2 = list2.size();
        int n = max(n1, n2);
        int carry = 0;

        for (int i = 0; i < n || carry; i++) {
            int x = (i < n1) ? list1[i] : 0;
            int y = (i < n2) ? list2[i] : 0;
            int sum = x + y + carry;
            ans.push_back(sum % 10);
            carry = sum / 10;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        for (int val : ans) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy->next;
    }
};
