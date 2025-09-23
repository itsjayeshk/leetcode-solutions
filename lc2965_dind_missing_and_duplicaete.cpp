class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        long long expectedSum = 1LL * total * (total + 1) / 2;

        vector<int> freq(total + 1, 0);
        long long actualSum = 0;
        int repeated = -1, missing = -1;

        // Count frequency and sum
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                actualSum += val;
                freq[val]++;
                if (freq[val] == 2) {
                    repeated = val;
                }
            }
        }

        // Missing = expectedSum - (actualSum - repeated)
        missing = expectedSum - (actualSum - repeated);

        return {repeated, missing};
    }
};
