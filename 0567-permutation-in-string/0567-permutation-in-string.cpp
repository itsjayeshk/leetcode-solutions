class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int freq1[26] = {0};
        int freq2[26] = {0};
        for (char c : s1) {
            freq1[c - 'a']++;
        }
        int window = s1.size();
        for (int i = 0; i < window; i++) {
            freq2[s2[i] - 'a']++;
        }
        if (isEqual(freq1, freq2)) return true;
        for (int i = window; i < s2.size(); i++) {
            freq2[s2[i] - 'a']++;              
            freq2[s2[i - window] - 'a']--;    
            if (isEqual(freq1, freq2)) return true;
        }
        return false;
    }
private:
    bool isEqual(int freq1[], int freq2[]) {
        for (int i = 0; i < 26; i++) {
            if (freq1[i] != freq2[i]) return false;
        }
        return true;
    }
};
