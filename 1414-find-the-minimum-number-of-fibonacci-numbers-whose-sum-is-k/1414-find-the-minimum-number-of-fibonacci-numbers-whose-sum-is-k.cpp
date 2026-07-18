class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = {1, 1};

        while (fib.back() < k) {
            int n = fib.size();
            fib.push_back(fib[n - 1] + fib[n - 2]);
        }

        int ans = 0;
        int i = fib.size() - 1;

        while (k > 0) {
            if (fib[i] <= k) {
                k -= fib[i];
                ans++;
            } else {
                i--;
            }
        }

        return ans;
    }
};