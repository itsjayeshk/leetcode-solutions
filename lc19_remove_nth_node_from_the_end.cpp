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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        ListNode* start = head;
        while(start != NULL){
            start = start->next;
            m = m + 1;
        }
        int k = m - n;
        if(k == 0){
            return head->next;
        }
        ListNode* slow = head;
        ListNode* ans = NULL;
        int i = 0;
        while(i < k){
            ans = slow;
            slow = slow->next;
            i = i + 1;

        }
        ans->next = slow->next;
        return head;
        
    }
};
