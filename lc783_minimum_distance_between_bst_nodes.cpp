class Solution {
public:
    int mindif = INT_MAX;
    TreeNode* prev = nullptr;

    void mindiff(TreeNode* root){
        if(root == nullptr){
            return;
        }
        mindiff(root->left);
        if(prev){
            mindif = min(mindif, root->val - prev->val);
        }
        prev = root; 
        mindiff(root->right); 
    }
    int minDiffInBST(TreeNode* root){
        mindiff(root);
        return mindif;
    }
};
