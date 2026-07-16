class Solution {
public:
    int gcd(int a, int b) {
        while (b) {
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<int> prefixGcd(n);
        for (int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            prefixGcd[i] = gcd(mx, nums[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans = 0;
        for (int i = 0; i < n / 2; i++) {
            ans = ans + gcd(prefixGcd[i], prefixGcd[n - i - 1]);
        }
        return ans;
    }
};