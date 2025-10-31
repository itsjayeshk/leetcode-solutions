class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        int n = s.size(), m = t.size();
        while(i < m && j < n){
            if(s[j] == t[i]){
                j = j + 1;
            }
            i = i + 1;
        }
        if(j == n){
            return true;
        }
        return false;
        
    }
};
