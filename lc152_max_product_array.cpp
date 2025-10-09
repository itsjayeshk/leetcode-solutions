class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxTillNow = nums[0];
        int minTillNow = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int curr = nums[i];

            int tempMax = max(curr, max(maxTillNow * curr, minTillNow * curr));
            minTillNow = min(curr, min(maxTillNow * curr, minTillNow * curr));
            maxTillNow = tempMax;

            ans = max(ans, maxTillNow);
        }
        return ans;
    }
};
