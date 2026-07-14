class Solution {
public:
    string getEncryptedString(string s, int k) {
        int m = s.size();
        int n = k % m;
        string ans = "";
        for (int i = 0; i < m; i++) {
            ans.push_back(s[(i + n) % m]);
        }
        return ans;
    }
};