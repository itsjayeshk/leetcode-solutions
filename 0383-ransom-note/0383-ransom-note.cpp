class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp1;
        for (char c : ransomNote) {
            mp1[c]++;
        }
        unordered_map<char, int> mp2;
        for (char c : magazine) {
            mp2[c]++;
        }

        for (auto it : mp1) {
            if (mp2[it.first] < it.second) {
                return false;
            }
        }
        return true;
    }
};