class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        n = (n - 1) % 14 + 1;

        while(n--){
            vector<int> ans(8, 0);

            for(int i = 1; i < 7; i++){
                if(cells[i - 1] == cells[i + 1]){
                    ans[i] = 1;
                }
            }

            cells = ans;
        }

        return cells;
    }
};