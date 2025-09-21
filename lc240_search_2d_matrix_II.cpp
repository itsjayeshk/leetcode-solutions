class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(),n = matrix[0].size();
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[j][i] == target){
                    return true;
                }
            }
        }
        return false;
        
    }
};
