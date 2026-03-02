class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i = 2;i < m;i++){
            for(int j = 0;i + j < m;j++){
                int k = i + j;
                dp[j][k] = INT_MAX;
                for(int l = j + 1;l < k;l++){
                    dp[j][k] = min(dp[j][k],dp[j][l] + dp[l][k] + cuts[k] - cuts[j]);
                }
                if(dp[j][k] == INT_MAX){
                dp[j][k] = 0;
            }
            }
            
        }
        return dp[0][m-1];
        
    }
};
