class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;

        if (digits.empty())
            return ans;

        vector<string> comb = {"",    "",    "abc",  "def", "ghi",
                               "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string temp;

        function<void(int)> solve = [&](int index) {
            if (index == digits.size()) {
                ans.push_back(temp);
                return;
            }

            int dig = digits[index] - '0';

            for (char ch : comb[dig]) {
                temp.push_back(ch);
                solve(index + 1);
                temp.pop_back();
            }
        };

        solve(0);
        return ans;
    }
};

