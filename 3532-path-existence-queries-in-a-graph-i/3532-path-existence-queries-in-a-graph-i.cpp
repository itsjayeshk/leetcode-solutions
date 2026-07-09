class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<int> comp(n, 0);
        int id = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff)
                id++;
            comp[i] = id;
        }

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(comp[queries[i][0]] == comp[queries[i][1]]);
        }

        return ans;
    }
};