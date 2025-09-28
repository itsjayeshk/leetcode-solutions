class Solution {
public:
    bool knight(vector<vector<int>> &grid, int row, int col, int n, int count){
        if(count == n*n - 1){
            return true;
        }
        int dr[8] = {1, 2, -2, -1, 2, -2, 1, -1};
        int dc[8] = {2, 1, -1, -2, -1, 1, -2, 2};
        for(int i=0;i<8;i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == count + 1){
                if(knight(grid, nr, nc, n, count + 1)){
                    return true;
                }
            }


        }
        return false;
        }
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] != 0){
            return false;
        }
        return knight(grid, 0, 0, n, 0);
        
    }
};
