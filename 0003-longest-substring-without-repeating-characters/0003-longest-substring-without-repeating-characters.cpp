class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int ans = 0;
        unordered_set<char> st;

        for (int right = 0; right < s.size(); right++) {

            while (st.find(s[right]) != st.end()) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[right]);

            ans = max(ans, right - l + 1);
        }

        return ans;
    }
};