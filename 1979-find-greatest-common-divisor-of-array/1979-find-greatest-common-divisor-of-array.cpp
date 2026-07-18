class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int m = min(nums[0], nums[nums.size() - 1]);
        int ans = 1;
        for (int i = 1; i <= m; i++) {
            if (nums[0] % i == 0 && nums[nums.size() - 1] % i == 0) {
                ans = i;
            }
        }
        return ans;
    }
};