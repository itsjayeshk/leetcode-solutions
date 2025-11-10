/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return issame(root,root);
        
        
    }
    bool issame(TreeNode* t1,TreeNode* t2){
        if(t1 == NULL && t2 == NULL){
            return true;
        }
        if(t1 == NULL || t2 == NULL){
            return false;
        }
        return (t1->val == t2->val) &&
               issame(t1->left, t2->right) &&
               issame(t1->right, t2->left);

    }
};
