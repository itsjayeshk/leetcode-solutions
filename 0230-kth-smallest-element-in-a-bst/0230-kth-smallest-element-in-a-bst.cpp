class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        inorder(root,nums);
        sort(nums.begin(),nums.end());
        return nums[k - 1];
    }
    
private:
    void inorder(TreeNode* root, vector<int>& nums){
        if(root == NULL){
            return;

        } 
        nums.push_back(root->val);
        inorder(root->left,nums);
        inorder(root->right,nums);
    }
};
