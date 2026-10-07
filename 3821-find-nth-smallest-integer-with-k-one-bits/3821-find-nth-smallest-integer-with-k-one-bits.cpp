#include <vector>

class Solution {
private:
    static const int MX = 50;
    long long C[MX][MX + 1];

    void precompute() {
        for (int i = 0; i < MX; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }

public:
    long long nthSmallest(long long n, int k) {
        precompute();
        long long ans = 0;
        
        for (int i = MX - 1; i >= 0; i--) {
            if (k == 0) break;
            
            if (n > C[i][k]) {
                n -= C[i][k];
                ans |= (1LL << i);
                k--;
            }
        }
        return ans;
    }
};
