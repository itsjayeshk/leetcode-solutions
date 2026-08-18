class Solution {
public:
    string decode(string s) {
        int m = s.size();
        string ans = "";

        int count = 1;

        for (int i = 1; i < m; i++) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                ans += to_string(count);
                ans += s[i - 1];
                count = 1;
            }
        }

        ans += to_string(count);
        ans += s[m - 1];

        return ans;
    }

    string countAndSay(int n) {
        vector<string> dp(n + 1);

        dp[1] = "1";

        for (int i = 2; i <= n; i++) {
            dp[i] = decode(dp[i - 1]);
        }

        return dp[n];
    }
};