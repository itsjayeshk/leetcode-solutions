class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;
        vector<int> ans;
        while (srow <= erow && scol <= ecol) {
            for (int j = scol; j <= ecol; j++) {
                ans.push_back(matrix[srow][j]);
            }
            for (int i = srow + 1; i <= erow; i++) {
                ans.push_back(matrix[i][ecol]);
            }

            if (srow < erow) {
                for (int j = ecol - 1; j >= scol; j--) {
                    ans.push_back(matrix[erow][j]);
                }
            }
            if (scol < ecol) {
                for (int i = erow - 1; i > srow; i--) {
                    ans.push_back(matrix[i][scol]);
                }
            }
            srow++; erow--;
            scol++; ecol--;
        }

        return ans;
    }
};
