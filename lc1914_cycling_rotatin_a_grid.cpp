class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(n, m) / 2;

        for (int layer = 0; layer < layers; layer++) {
            int left = layer;
            int top = layer;
            int right = n - layer - 1;
            int bottom = m - layer - 1;

            vector<int> elements;

            for (int i = left; i <= right; i++) {
                elements.push_back(grid[top][i]);
            }

            for (int j = top + 1; j < bottom; j++) {
                elements.push_back(grid[j][right]);
            }

            for (int j = right; j >= left; j--) {
                elements.push_back(grid[bottom][j]);
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                elements.push_back(grid[i][left]);
            }

            int len = elements.size();
            int rotation = k % len;

            vector<int> rotated(len);

            for (int i = 0; i < len; i++) {
                rotated[i] = elements[(i + rotation) % len];
            }

            int idx = 0;

            for (int j = left; j <= right; j++) {
                grid[top][j] = rotated[idx++];
            }

            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = rotated[idx++];
            }

            for (int j = right; j >= left; j--) {
                grid[bottom][j] = rotated[idx++];
            }

            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = rotated[idx++];
            }
        }

        return grid;
    }
};
