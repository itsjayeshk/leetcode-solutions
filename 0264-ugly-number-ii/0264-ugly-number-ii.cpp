class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n);
        dp[0] = 1;
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        for(int i = 1;i < n;i++){
            long long next2 = dp[i2] * 2;
            long long next3 = dp[i3] * 3;
            long long next5 = dp[i5] * 5;

            dp[i] = min({next2,next3,next5});

            if (dp[i] == next2) i2++;
            if (dp[i] == next3) i3++;
            if (dp[i] == next5) i5++;

            

        }
        return dp[n - 1];
        
    }
};