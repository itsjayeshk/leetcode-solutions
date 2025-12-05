class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++){
            bool unique = true;
            for(int j = 0; j < nums.size(); j++){
                if(i != j && nums[j] == nums[i]){
                    unique = false;
                    break;
                }
            }
            if(unique){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
