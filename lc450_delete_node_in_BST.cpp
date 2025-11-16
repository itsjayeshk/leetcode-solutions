class Solution {
public: 
    TreeNode* getsuccessor(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return nullptr;
        }
        if(key < root->val){
            root->left = deleteNode(root->left,key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right,key);
        }
        else{
            if(root->left == NULL && root->right == NULL){
                delete root;
                return nullptr;
            }
            if(root->left == NULL && root->right != NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            if(root->right == NULL && root->left != NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            if(root->left != NULL && root->right != NULL){
                TreeNode* successor = getsuccessor(root->right);
                root->val = successor->val;
                root->right = deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};
