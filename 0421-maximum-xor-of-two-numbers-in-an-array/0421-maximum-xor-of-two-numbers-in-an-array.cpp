class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;

        for (int bit = 31; bit >= 0; bit--) {

            mask |= (1 << bit);

            unordered_set<int> st;

            for (int num : nums) {
                st.insert(num & mask);
            }

            int candidate = ans | (1 << bit);

            for (int prefix : st) {
                int required = prefix ^ candidate;

                if (st.count(required)) {
                    ans = candidate;
                    break;
                }
            }
        }

        return ans;
    }
};