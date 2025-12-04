class Solution {
public:
    int titleToNumber(string columnTitle) {
        long ans = 0;
        for(char c : columnTitle){
            ans = ans * 26 + (c - 'A' + 1);
        }
        return ans;
    }
};
