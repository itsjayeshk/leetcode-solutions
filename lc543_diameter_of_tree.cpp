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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftd = diameterOfBinaryTree(root->left);
        int rightd = diameterOfBinaryTree(root->right);
        int lefth = height(root->left);
        int righth = height(root->right);
        return max(lefth + righth,max(leftd,rightd));
              
    }
    int height(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        return 1 + max(height(node->left),height(node->right));
    }
};
