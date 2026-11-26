class Solution {
public:
    bool canAliceWin(int n) {
        int s = 10;
        int cnt = 0;
        while (n >= s) {
            n = n - s;
            cnt++;
            s--;
        }
        if (cnt % 2 == 0) {
            return false;
        } else {
            return true;
        }
        return false;
    }
};