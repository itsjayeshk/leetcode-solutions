class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root){
        return diam2(root).first;
    }
    pair<int, int> diam2(TreeNode* root){
        if(root == NULL){
            return {0, 0};

        }  
        pair<int, int> leftInfo = diam2(root->left);
        pair<int, int> rightInfo = diam2(root->right);
        int leftDiameter = leftInfo.first;
        int rightDiameter = rightInfo.first;
        int leftHeight = leftInfo.second;
        int rightHeight = rightInfo.second;
        int currDiameter = leftHeight + rightHeight;
        int finalDiameter = max(currDiameter,max(leftDiameter,rightDiameter));
        int finalHeight = 1 + max(leftHeight,rightHeight);
        return {finalDiameter,finalHeight};
    }
};
