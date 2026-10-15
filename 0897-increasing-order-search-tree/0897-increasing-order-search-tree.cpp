
class Solution {
public:
    void traverse(TreeNode* node, vector<TreeNode*>& ans) {
        if (node == nullptr) {
            return;
        }

        traverse(node->left, ans);
        ans.push_back(node);
        traverse(node->right, ans);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> ans;
        traverse(root, ans);

        TreeNode* dummy = new TreeNode(0);
        TreeNode* curr = dummy;

        for (TreeNode* node : ans) {
            node->left = nullptr;
            curr->right = node;
            curr = node;
        }

        curr->right = nullptr;

        return dummy->right;
    }
};
