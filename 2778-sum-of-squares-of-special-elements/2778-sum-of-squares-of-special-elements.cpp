
class Solution {
public:
    int square(int n) { return n * n; }

    int sumOfSquares(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                ans += square(nums[i - 1]);
            }
        }

        return ans;
    }
};
