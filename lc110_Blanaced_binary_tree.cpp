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
    bool isBalanced(TreeNode* root) {
        if(check(root) == -1){
            return false;
        }
        return true;
        
    }
    int check(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int left = check(node->left);
        if(left == -1){
            return -1;
        }
        int right = check(node->right);
        if(right == -1){
            return -1;
        }
        if(abs(right - left) > 1){
            return -1;
        }
        return 1 + max(left, right);


    }
};
