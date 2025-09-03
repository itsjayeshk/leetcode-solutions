class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        int n = accounts.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < accounts[i].size(); j++) {
                sum = sum + accounts[i][j];
            }
            maxWealth = max(maxWealth, sum);
        }
        return maxWealth;
    }
};
