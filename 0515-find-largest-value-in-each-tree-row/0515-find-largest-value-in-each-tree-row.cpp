class Solution {
public:
    vector<int> ans;

    void dfs(TreeNode* root, int level) {
        if (!root) return;

        if (level == ans.size())
            ans.push_back(root->val);
        else
            ans[level] = max(ans[level], root->val);

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};