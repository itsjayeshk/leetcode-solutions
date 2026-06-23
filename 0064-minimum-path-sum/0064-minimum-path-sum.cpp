class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);

        dp[0] = grid[0][0];

        for (int i = 1; i < n; i++) {
            dp[i] = dp[i - 1] + grid[0][i];
        }

        for (int j = 1; j < m; j++) {
            dp[0] = dp[0] + grid[j][0];

            for (int i = 1; i < n; i++) {
                dp[i] = min(dp[i], dp[i - 1]) + grid[j][i];
            }
        }

        return dp[n - 1];
    }
};