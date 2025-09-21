class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int startr = 0, endr = m - 1;
        while (startr <= endr) {
            int midrow = startr + (endr - startr) / 2;
            if (target >= matrix[midrow][0] && target <= matrix[midrow][n - 1]) {
                int l = 0, r = n - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (matrix[midrow][mid] == target) return true;
                    else if (matrix[midrow][mid] < target) l = mid + 1;
                    else r = mid - 1;
                }
                return false;
            }
            else if (target > matrix[midrow][n - 1]) {
                startr = midrow + 1;
            }
            else {
                endr = midrow - 1;
            }
        }
        return false;
    }
};
