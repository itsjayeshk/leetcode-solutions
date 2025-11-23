class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);   
        for (int i = 0;i < nums.size();i++){
            if(nums[i] == target){
                ans[0] = i;
                break;
            }
        }

        for(int j = nums.size() - 1;j >= 0;j--){
            if(nums[j] == target){
                ans[1] = j;
                break;
            }
        }

        return ans;
    }
};
