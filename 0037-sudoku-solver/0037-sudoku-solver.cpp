class Solution {
public:
    bool issafe(vector<vector<char>>& board, int row, int col, char i){
        for(int j=0;j<9;j++){
            if(board[row][j] == i){
                return false;
            }
        }
        for(int p=0;p<9;p++){
            if(board[p][col] == i){
                return false;
            }
        }
        int srow = (row/3)*3;
        int scol = (col/3)*3;
        for(int q = srow; q <= srow+2;q++){
            for(int k = scol; k <= scol+2;k++){
                if(board[q][k] == i){
                    return false;
                }
            }
        }
        return true;
    }

    bool checker(vector<vector<char>>& board, int row, int col){
        if(row == 9){   
            return true;
        }
        int nextrow = row, nextcol = col + 1;
        if(nextcol == 9){
            nextrow = row+1;
            nextcol = 0;
        }
        if(board[row][col] != '.'){
            return checker(board, nextrow, nextcol);
        }
        for(char i='1'; i<='9';i++){  
            if(issafe(board, row, col, i)){
                board[row][col] = i;
                if(checker(board, nextrow, nextcol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;  
    }

    void solveSudoku(vector<vector<char>>& board) {
        checker(board, 0, 0);  
    }
};
