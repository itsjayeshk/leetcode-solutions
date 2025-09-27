class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans;  
        int n = grid.size();
        int expsum = (n * n * (n * n + 1)) / 2;  
        int actsum = 0;
        int a = 0, d = 0, b = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                actsum = actsum + grid[i][j];
            }
        }

        if(actsum > expsum){
            d = actsum - expsum;   
        }
        if(actsum < expsum){
            d = expsum - actsum;   
        }

        
        for(int p = 0; p < n; p++){
            for(int q = 0; q < n; q++){
                int count = 0;
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(grid[i][j] == grid[p][q]){
                            count++;
                        }
                    }
                }
                if(count > 1){
                    a = grid[p][q];
                }
            }
        }

        ans.push_back(a);

        if(expsum > actsum){
            b = a + d;
        }
        if(expsum < actsum){
            b = a - d;
        }

        ans.push_back(b);
        return ans;
    }
};
