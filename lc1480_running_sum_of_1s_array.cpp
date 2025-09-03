class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int sum=0;
        for(int i=0;i<n;i++){
            ans[i] = sum + nums[i];
            sum = sum + nums[i];
        }
        return ans;
        
    }
};
