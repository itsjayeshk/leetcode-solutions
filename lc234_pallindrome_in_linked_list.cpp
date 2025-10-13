class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> ans;
        while(head){
            ans.push_back(head->val);
            head = head->next;
        }
        int i = 0,j = ans.size() - 1;
        while(i<j){
            if(ans[i] == ans[j]){
                i++;
                j--;
            }
            if(ans[i] != ans[j]){
                return false;
            }


        }
        return true;
        
        
    }
};
