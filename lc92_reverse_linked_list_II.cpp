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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head){
            return head;
        }
        vector<int> vals;
        ListNode* temp = head;
        while(temp){
            vals.push_back(temp->val);
            temp = temp->next;

        }
        reverse(vals.begin() + (left - 1),vals.begin() + right);
        temp = head;
        int i = 0;
        while(temp){
            temp->val = vals[i];
            i++;
            temp = temp->next;
        }
        return head;

        
    }
};
