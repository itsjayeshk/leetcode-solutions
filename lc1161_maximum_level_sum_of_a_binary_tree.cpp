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
    void rowsum(TreeNode* node,vector<int>& sum,int level) {
        if(!node) return;
        if(sum.size() == level){
            sum.push_back(0);
        }
        sum[level] = sum[level] + node->val;
        rowsum(node->left,sum,level + 1);
        rowsum(node->right,sum,level + 1);
    }

    int maxLevelSum(TreeNode* root){
        vector<int> sum;
        rowsum(root,sum,0);
        int maxsum = INT_MIN,ans = 0;
        for(int i = 0;i < sum.size();i++){
            if(sum[i] > maxsum){
                maxsum = sum[i];
                ans = i + 1; 
            }
        }
        return ans;
    }
};
