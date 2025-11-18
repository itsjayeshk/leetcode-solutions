class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;
        getvector(root, nums);
        return buildbst(nums,0,nums.size() - 1);
    }

    TreeNode* buildbst(vector<int>& nums, int low, int high){
        if(low > high){
            return nullptr;
        }
        int mid = low + (high - low)/2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = buildbst(nums,low,mid - 1);
        curr->right = buildbst(nums,mid + 1,high);
        return curr;
    }

    void getvector(TreeNode* root, vector<int>& nums){ 
        if(root == NULL){
            return;
        }
        getvector(root->left,nums);
        nums.push_back(root->val);
        getvector(root->right, nums);
    }
};
