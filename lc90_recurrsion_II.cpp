class Solution {
public:
    void getallsubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allsubsets) {
        allsubsets.push_back(ans); 

        for(int idx = i; idx < nums.size(); idx++) {
            
            if(idx > i && nums[idx] == nums[idx - 1]) continue;

            ans.push_back(nums[idx]);
            getallsubsets(nums, ans, idx + 1, allsubsets);
            ans.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allsubsets;
        vector<int> ans;
        getallsubsets(nums, ans, 0, allsubsets);
        return allsubsets;
    }
};
