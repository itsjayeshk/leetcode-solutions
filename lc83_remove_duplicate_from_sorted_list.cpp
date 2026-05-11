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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> vtemp;
        ListNode* temp = head;

        while(temp != NULL){
            vtemp.push_back(temp->val);
            temp = temp->next;
        }

        vector<int> ftemp;

        sort(vtemp.begin(), vtemp.end());

        if(vtemp.size() > 0){
            ftemp.push_back(vtemp[0]);
        }

        for(int i = 1; i < vtemp.size(); i++){
            if(vtemp[i] != vtemp[i - 1]){
                ftemp.push_back(vtemp[i]);
            }
        }

        temp = head;
        int i = 0;

        while(temp != NULL && i < ftemp.size()){
            temp->val = ftemp[i++];
            
            if(i == ftemp.size()){
                temp->next = NULL;
                break;
            }

            temp = temp->next;
        }

        return head;
    }
};;
