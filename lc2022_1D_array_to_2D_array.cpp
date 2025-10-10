class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int k = original.size();
        if (k != m * n) return {}; 
        
        vector<vector<int>> arr(m, vector<int>(n));
        
        for (int i = 0; i < k; i++) {
            arr[i / n][i % n] = original[i]; 
        }
        
        return arr;
    }
};
