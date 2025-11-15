class Solution {
public:
    int i = 0;

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MIN, INT_MAX);
    }

    TreeNode* build(vector<int>& preorder, int low, int high) {
        if(i == preorder.size()){
            return nullptr; 
        }
        int value = preorder[i];
        if(value < low || value > high){
            return nullptr;
        }
        i++;
        TreeNode* root = new TreeNode(value);
        root->left = build(preorder,low,value - 1);
        root->right = build(preorder,value + 1,high);
        return root;
    }
};
