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
    ListNode* sortList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        vector<int> list;
        ListNode* curr = head;
        while(curr != nullptr){
            list.push_back(curr->val);
            curr = curr->next;
        }
        sort(list.begin(),list.end());
        ListNode* sort = head;
        for(int i = 0;i < list.size();i++){
            sort->val = list[i];
            sort = sort->next;
        }
        return head;
        
    }
};