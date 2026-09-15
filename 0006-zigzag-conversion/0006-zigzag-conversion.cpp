class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> ans(numRows);
        if (numRows == 1) {
            return s;
        }
        int row = 0;
        int dir = 1;
        for (char c : s) {
            ans[row] = ans[row] + c;
            if (row == 0) {
                dir = 1;
            } else if (row == numRows - 1) {
                dir = -1;
            }
            row = row + dir;
        }
        string answer;
        for (string a : ans) {
            answer = answer + a;
        }
        return answer;
    }
};