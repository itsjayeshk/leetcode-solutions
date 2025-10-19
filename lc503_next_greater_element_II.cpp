class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int found = -1;
            for(int j = 1; j < n; j++){
                if(nums[(i + j) % n] > nums[i]){
                    found = nums[(i + j) % n];
                    break;
                }
            }
            ans.push_back(found);
        }
        return ans;
    }
};
