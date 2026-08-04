class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int maxi = nums[nums.size() - 1];
        vector<int> ans;
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = mini; i <= maxi; i++) {
            if (!s.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};